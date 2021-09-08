import * as THREE from './libs/three.module.js';

import { UIPanel, UIRow, UIHorizontalRule } from './libs/ui.js';

import { AddNodeCommand } from './commands/AddNodeCommand.js';

function MenubarAdd( editor ) {

	var strings = editor.strings;

	var container = new UIPanel();
	container.setClass( 'menu' );

	var title = new UIPanel();
	title.setClass( 'title' );
	title.setTextContent( strings.getKey( 'menubar/add' ) );
	container.add( title );

	var options = new UIPanel();
	options.setClass( 'options' );
	container.add( options );

	// Node
	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/node' ) );
	option.onClick( function () {

		var node = new cc.Node();
		node.name = 'Node';
		node.uuid = THREE.MathUtils.generateUUID()
		editor.execute( new AddNodeCommand( editor, node ) );

	} );
	options.add( option );

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/sprite' ) );
	option.onClick( function () {

		var sprite = new cc.Sprite();
		sprite.name = 'Sprite';
		sprite.uuid = THREE.MathUtils.generateUUID()
		editor.execute( new AddNodeCommand( editor, sprite ) );

	} );
	options.add( option );

	//

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/label' ) );
	option.onClick( function () {

		var label = new cc.Label();
		label.name = 'Label';
		label.uuid = THREE.MathUtils.generateUUID()
		editor.execute( new AddNodeCommand( editor, label ) );

	} );
	options.add( option );

	options.add( new UIHorizontalRule() );

	/*
	// Teapot

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( 'Teapot' );
	option.onClick( function () {

		var size = 50;
		var segments = 10;
		var bottom = true;
		var lid = true;
		var body = true;
		var fitLid = false;
		var blinnScale = true;

		var material = new THREE.MeshStandardMaterial();

		var geometry = new TeapotGeometry( size, segments, bottom, lid, body, fitLid, blinnScale );
		var mesh = new THREE.Mesh( geometry, material );
		mesh.name = 'Teapot';

		editor.addObject( mesh );
		editor.select( mesh );

	} );
	options.add( option );
	*/

	//

	options.add( new UIHorizontalRule() );
	/*
	// AmbientLight

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/ambientlight' ) );
	option.onClick( function () {

		var color = 0x222222;

		var light = new THREE.AmbientLight( color );
		light.name = 'AmbientLight';

		editor.execute( new AddNodeCommand( editor, light ) );

	} );
	options.add( option );

	// DirectionalLight

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/directionallight' ) );
	option.onClick( function () {

		var color = 0xffffff;
		var intensity = 1;

		var light = new THREE.DirectionalLight( color, intensity );
		light.name = 'DirectionalLight';
		light.target.name = 'DirectionalLight Target';

		light.position.set( 5, 10, 7.5 );

		editor.execute( new AddNodeCommand( editor, light ) );

	} );
	options.add( option );

	// HemisphereLight

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/hemispherelight' ) );
	option.onClick( function () {

		var skyColor = 0x00aaff;
		var groundColor = 0xffaa00;
		var intensity = 1;

		var light = new THREE.HemisphereLight( skyColor, groundColor, intensity );
		light.name = 'HemisphereLight';

		light.position.set( 0, 10, 0 );

		editor.execute( new AddNodeCommand( editor, light ) );

	} );
	options.add( option );

	// PointLight

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/pointlight' ) );
	option.onClick( function () {

		var color = 0xffffff;
		var intensity = 1;
		var distance = 0;

		var light = new THREE.PointLight( color, intensity, distance );
		light.name = 'PointLight';

		editor.execute( new AddNodeCommand( editor, light ) );

	} );
	options.add( option );

	// SpotLight

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/spotlight' ) );
	option.onClick( function () {

		var color = 0xffffff;
		var intensity = 1;
		var distance = 0;
		var angle = Math.PI * 0.1;
		var penumbra = 0;

		var light = new THREE.SpotLight( color, intensity, distance, angle, penumbra );
		light.name = 'SpotLight';
		light.target.name = 'SpotLight Target';

		light.position.set( 5, 10, 7.5 );

		editor.execute( new AddNodeCommand( editor, light ) );

	} );
	options.add( option );

	//

	options.add( new UIHorizontalRule() );

	// OrthographicCamera

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/orthographiccamera' ) );
	option.onClick( function () {

		var aspect = editor.camera.aspect;
		var camera = new THREE.OrthographicCamera( - aspect, aspect );
		camera.name = 'OrthographicCamera';

		editor.execute( new AddNodeCommand( editor, camera ) );

	} );
	options.add( option );

	// PerspectiveCamera

	var option = new UIRow();
	option.setClass( 'option' );
	option.setTextContent( strings.getKey( 'menubar/add/perspectivecamera' ) );
	option.onClick( function () {

		var camera = new THREE.PerspectiveCamera();
		camera.name = 'PerspectiveCamera';

		editor.execute( new AddNodeCommand( editor, camera ) );

	} );
	options.add( option );
	*/
	return container;

}

export { MenubarAdd };
