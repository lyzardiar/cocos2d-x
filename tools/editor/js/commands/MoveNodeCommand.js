import { Command } from '../Command.js';

/**
 * @param editor Editor
 * @param object THREE.Object3D
 * @param newParent THREE.Object3D
 * @param newBefore THREE.Object3D
 * @constructor
 */
class MoveNodeCommand extends Command {

	constructor( editor, node, newParent, newBefore ) {

		super( editor );

		this.type = 'MoveNodeCommand';
		this.name = 'Move Node';

		this.node = node;
		this.oldParent = ( node !== undefined ) ? node.parent : undefined;
		this.oldIndex = ( this.oldParent !== undefined ) ? this.oldParent.children.indexOf( this.node ) : undefined;
		this.newParent = newParent;

		if ( newBefore !== undefined ) {

			this.newIndex = ( newParent !== undefined ) ? newParent.children.indexOf( newBefore ) : undefined;

		} else {

			this.newIndex = ( newParent !== undefined ) ? newParent.children.length : undefined;

		}

		if ( this.oldParent === this.newParent && this.newIndex > this.oldIndex ) {

			this.newIndex --;

		}

		this.newBefore = newBefore;

	}

	execute() {

		this.oldParent.remove( this.node );

		const children = this.newParent.children;
		children.splice( this.newIndex, 0, this.node );
		this.node.parent = this.newParent;

		this.node.dispatchEvent( { type: 'added' } );
		this.editor.signals.sceneGraphChanged.dispatch();

	}

	undo() {

		this.newParent.remove( this.node );

		const children = this.oldParent.children;
		children.splice( this.oldIndex, 0, this.node ); // TODO: add child at index
		this.node.parent = this.oldParent;

		this.node.dispatchEvent( { type: 'added' } );
		this.editor.signals.sceneGraphChanged.dispatch();

	}

	toJSON() {

		const output = super.toJSON( this );

		output.nodeUuid = this.node.uuid;
		output.newParentUuid = this.newParent.uuid;
		output.oldParentUuid = this.oldParent.uuid;
		output.newIndex = this.newIndex;
		output.oldIndex = this.oldIndex;

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.node = this.editor.nodeByUuid( json.nodeUuid );
		this.oldParent = this.editor.nodeByUuid( json.oldParentUuid );
		if ( this.oldParent === undefined ) {

			this.oldParent = this.editor.scene;

		}

		this.newParent = this.editor.nodeByUuid( json.newParentUuid );

		if ( this.newParent === undefined ) {

			this.newParent = this.editor.scene;

		}

		this.newIndex = json.newIndex;
		this.oldIndex = json.oldIndex;

	}

}

export { MoveNodeCommand };
