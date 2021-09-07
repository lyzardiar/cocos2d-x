import * as THREE from './libs/three.module.js';

function EditorControls( node, domElement ) {

	// API

	this.enabled = true;
	this.center = {x: 0, y: 0};
	this.panSpeed = 0.002;
	this.zoomSpeed = 0.1;
	this.rotationSpeed = 0.005;

	// internals

	var scope = this;
	var vector = {x: 0, y: 0, z: 0};
	var delta = {x: 0, y: 0, z: 0};
	var box = new THREE.Box3();

	var STATE = { NONE: - 1, ROTATE: 0, ZOOM: 1, PAN: 2 };
	var state = STATE.NONE;

	var center = this.center;
	var normalMatrix = new THREE.Matrix3();
	var pointer = {x: 0, y: 0};
	var pointerOld = {x: 0, y: 0};
	var spherical = new THREE.Spherical();
	var sphere = new THREE.Sphere();

	// events

	var changeEvent = { type: 'change' };

	this.focus = function ( target ) {

		var distance = 0.1

		var box = target.getBoundingBox()
		center.x = box.origin.x + box.size.width / 2
		center.y = box.origin.y + box.size.height / 2
		
		

		// delta.set( 0, 0, 1 );
		// delta.applyQuaternion( node.quaternion );
		// delta.multiplyScalar( distance * 4 );
		// TODO: missing distance
		node.position = center

		scope.dispatchEvent( changeEvent );

	};

	this.pan = function ( delta ) {
		
		var distance = Math.hypot(node.position.x - center.x, node.position.y - center.y)

		delta.multiplyScalar( distance * scope.panSpeed );
		delta.applyMatrix3( normalMatrix.getNormalMatrix( node.matrix ) );

		node.position.add( delta );
		center.add( delta );

		scope.dispatchEvent( changeEvent );

	};

	this.zoom = function ( delta ) {

		var distance = node.position.distanceTo( center );

		delta.multiplyScalar( distance * scope.zoomSpeed );

		if ( delta.length() > distance ) return;

		delta.applyMatrix3( normalMatrix.getNormalMatrix( node.matrix ) );

		node.position.add( delta );

		scope.dispatchEvent( changeEvent );

	};

	this.rotate = function ( delta ) {

		vector.copy( node.position ).sub( center );

		spherical.setFromVector3( vector );

		spherical.theta += delta.x * scope.rotationSpeed;
		spherical.phi += delta.y * scope.rotationSpeed;

		spherical.makeSafe();

		vector.setFromSpherical( spherical );

		node.position.copy( center ).add( vector );

		node.lookAt( center );

		scope.dispatchEvent( changeEvent );

	};

	//

	function onPointerDown( event ) {

		if ( scope.enabled === false ) return;

		switch ( event.pointerType ) {

			case 'mouse':
			case 'pen':
				onMouseDown( event );
				break;

			// TODO touch

		}

		domElement.ownerDocument.addEventListener( 'pointermove', onPointerMove, false );
		domElement.ownerDocument.addEventListener( 'pointerup', onPointerUp, false );

	}

	function onPointerMove( event ) {

		if ( scope.enabled === false ) return;

		switch ( event.pointerType ) {

			case 'mouse':
			case 'pen':
				onMouseMove( event );
				break;

			// TODO touch

		}

	}

	function onPointerUp( event ) {

		switch ( event.pointerType ) {

			case 'mouse':
			case 'pen':
				onMouseUp();
				break;

			// TODO touch

		}

		domElement.ownerDocument.removeEventListener( 'pointermove', onPointerMove, false );
		domElement.ownerDocument.removeEventListener( 'pointerup', onPointerUp, false );

	}

	// mouse

	function onMouseDown( event ) {

		if ( event.button === 0 ) {

			state = STATE.ROTATE;

		} else if ( event.button === 1 ) {

			state = STATE.ZOOM;

		} else if ( event.button === 2 ) {

			state = STATE.PAN;

		}

		pointerOld.set( event.clientX, event.clientY );

	}

	function onMouseMove( event ) {

		pointer.set( event.clientX, event.clientY );

		var movementX = pointer.x - pointerOld.x;
		var movementY = pointer.y - pointerOld.y;

		if ( state === STATE.ROTATE ) {

			scope.rotate( delta.set( - movementX, - movementY, 0 ) );

		} else if ( state === STATE.ZOOM ) {

			scope.zoom( delta.set( 0, 0, movementY ) );

		} else if ( state === STATE.PAN ) {

			scope.pan( delta.set( - movementX, movementY, 0 ) );

		}

		pointerOld.set( event.clientX, event.clientY );

	}

	function onMouseUp() {

		state = STATE.NONE;

	}

	function onMouseWheel( event ) {

		if ( scope.enabled === false ) return;

		event.preventDefault();

		// Normalize deltaY due to https://bugzilla.mozilla.org/show_bug.cgi?id=1392460
		scope.zoom( delta.set( 0, 0, event.deltaY > 0 ? 1 : - 1 ) );

	}

	function contextmenu( event ) {

		event.preventDefault();

	}

	this.dispose = function () {

		domElement.removeEventListener( 'contextmenu', contextmenu, false );
		domElement.removeEventListener( 'dblclick', onMouseUp, false );
		domElement.removeEventListener( 'wheel', onMouseWheel, false );

		domElement.removeEventListener( 'pointerdown', onPointerDown, false );

		domElement.removeEventListener( 'touchstart', touchStart, false );
		domElement.removeEventListener( 'touchmove', touchMove, false );

	};

	domElement.addEventListener( 'contextmenu', contextmenu, false );
	domElement.addEventListener( 'dblclick', onMouseUp, false );
	domElement.addEventListener( 'wheel', onMouseWheel, false );

	domElement.addEventListener( 'pointerdown', onPointerDown, false );

	// touch

	var touches = [ new THREE.Vector3(), new THREE.Vector3(), new THREE.Vector3() ];
	var prevTouches = [ new THREE.Vector3(), new THREE.Vector3(), new THREE.Vector3() ];

	var prevDistance = null;

	function touchStart( event ) {

		if ( scope.enabled === false ) return;

		switch ( event.touches.length ) {

			case 1:
				touches[ 0 ].set( event.touches[ 0 ].pageX, event.touches[ 0 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				touches[ 1 ].set( event.touches[ 0 ].pageX, event.touches[ 0 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				break;

			case 2:
				touches[ 0 ].set( event.touches[ 0 ].pageX, event.touches[ 0 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				touches[ 1 ].set( event.touches[ 1 ].pageX, event.touches[ 1 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				prevDistance = touches[ 0 ].distanceTo( touches[ 1 ] );
				break;

		}

		prevTouches[ 0 ].copy( touches[ 0 ] );
		prevTouches[ 1 ].copy( touches[ 1 ] );

	}


	function touchMove( event ) {

		if ( scope.enabled === false ) return;

		event.preventDefault();
		event.stopPropagation();

		function getClosest( touch, touches ) {

			var closest = touches[ 0 ];

			for ( var i in touches ) {

				if ( closest.distanceTo( touch ) > touches[ i ].distanceTo( touch ) ) closest = touches[ i ];

			}

			return closest;

		}

		switch ( event.touches.length ) {

			case 1:
				touches[ 0 ].set( event.touches[ 0 ].pageX, event.touches[ 0 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				touches[ 1 ].set( event.touches[ 0 ].pageX, event.touches[ 0 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				scope.rotate( touches[ 0 ].sub( getClosest( touches[ 0 ], prevTouches ) ).multiplyScalar( - 1 ) );
				break;

			case 2:
				touches[ 0 ].set( event.touches[ 0 ].pageX, event.touches[ 0 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				touches[ 1 ].set( event.touches[ 1 ].pageX, event.touches[ 1 ].pageY, 0 ).divideScalar( window.devicePixelRatio );
				var distance = touches[ 0 ].distanceTo( touches[ 1 ] );
				scope.zoom( delta.set( 0, 0, prevDistance - distance ) );
				prevDistance = distance;


				var offset0 = touches[ 0 ].clone().sub( getClosest( touches[ 0 ], prevTouches ) );
				var offset1 = touches[ 1 ].clone().sub( getClosest( touches[ 1 ], prevTouches ) );
				offset0.x = - offset0.x;
				offset1.x = - offset1.x;

				scope.pan( offset0.add( offset1 ) );

				break;

		}

		prevTouches[ 0 ].copy( touches[ 0 ] );
		prevTouches[ 1 ].copy( touches[ 1 ] );

	}

	domElement.addEventListener( 'touchstart', touchStart, false );
	domElement.addEventListener( 'touchmove', touchMove, false );

}

EditorControls.prototype = Object.create( THREE.EventDispatcher.prototype );
EditorControls.prototype.constructor = EditorControls;

export { EditorControls };
