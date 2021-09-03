import { Command } from '../Command.js';
import { ObjectLoader } from '../libs/three.module.js';

/**
 * @param editor Editor
 * @param node cc.Node
 * @constructor
 */
class AddNodeCommand extends Command {

	constructor( editor, node ) {

		super( editor );

		this.type = 'AddNodeCommand';

		this.node = node;
		if ( node !== undefined ) {

			this.name = `Add Node: ${node.name}`;

		}

	}

	execute() {

		this.editor.addNode( this.node );
		this.editor.select( this.node );

	}

	undo() {

		this.editor.removeNode( this.node );
		this.editor.deselect();

	}

	toJSON() {

		const output = super.toJSON( this );
		// TODO: guess we don't have this
		output.node = this.node.toJSON();

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );
		// TODO: guess we don't have this
		this.node = this.editor.nodeByUuid( json.object.node.uuid );

		if ( this.node === undefined ) {

			const loader = new ObjectLoader();
			this.node = loader.parse( json.object );

		}

	}

}

export { AddNodeCommand };
