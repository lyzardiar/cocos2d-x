import { Command } from '../Command.js';
import { Vector3 } from '../libs/three.module.js';

/**
 * @param editor Editor
 * @param object THREE.Object3D
 * @param newPosition THREE.Vector3
 * @param optionalOldPosition THREE.Vector3
 * @constructor
 */
class SetPositionCommand extends Command {

	constructor( editor, node, newPosition, optionalOldPosition ) {

		super( editor );

		this.type = 'SetPositionCommand';
		this.name = 'Set Position';
		this.updatable = true;

		this.node = node;

		if ( node !== undefined && newPosition !== undefined ) {

			this.oldPosition = Object.assign({}, node.position);
			this.newPosition = Object.assign({}, newPosition);
		}

		if ( optionalOldPosition !== undefined ) {

			this.oldPosition = Object.assign({}, optionalOldPosition);

		}

	}

	execute() {

		this.node.position = this.newPosition
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	undo() {

		this.node.position = this.oldPosition
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	update( command ) {
		this.newPosition = Object.assign(this.newPosition, command.newPosition);
	}

	toJSON() {

		const output = super.toJSON( this );

		output.objectUuid = this.object.uuid;
		output.oldPosition = this.oldPosition.toArray();
		output.newPosition = this.newPosition.toArray();

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.object = this.editor.objectByUuid( json.objectUuid );
		this.oldPosition = new Vector3().fromArray( json.oldPosition );
		this.newPosition = new Vector3().fromArray( json.newPosition );

	}

}

export { SetPositionCommand };
