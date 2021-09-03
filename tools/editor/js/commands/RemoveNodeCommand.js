import { Command } from '../Command.js';

import { ObjectLoader } from '../libs/three.module.js';

/**
 * @param editor Editor
 * @param node cc.Node
 * @constructor
 */
class RemoveNodeCommand extends Command {

	constructor( editor, node ) {

		super( editor );

		this.type = 'RemoveNodeCommand';
		this.name = 'Remove Node';

		this.node = node;
		this.parent = ( node !== undefined ) ? node.parent : undefined;
		if ( this.parent !== undefined ) {

			this.index = this.parent.children.indexOf( this.node );

		}

	}

	execute() {

		this.editor.removeNode( this.node );
		this.editor.deselect();

	}

	undo() {

		this.editor.addNode( this.node, this.parent, this.index );
		this.editor.select( this.node );

	}

	toJSON() {

		const output = super.toJSON( this );

		output.node = this.node.toJSON();
		output.index = this.index;
		output.parentUuid = this.parent.uuid;

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.parent = this.editor.nodeByUuid( json.parentUuid );
		if ( this.parent === undefined ) {

			this.parent = this.editor.scene;

		}

		this.index = json.index;

		this.node = this.editor.nodeByUuid( json.node.object.uuid );

		if ( this.node === undefined ) {

			const loader = new ObjectLoader();
			this.node = loader.parse( json.node );

		}

	}

}

export { RemoveNodeCommand };
