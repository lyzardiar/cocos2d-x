import { Command } from '../Command.js';
import { Euler } from '../libs/three.module.js';

/**
 * @param editor Editor
 * @param object THREE.Object3D
 * @param newRotation THREE.Euler
 * @param optionalOldRotation THREE.Euler
 * @constructor
 */
class SetRotationCommand extends Command {

	constructor( editor, node, newRotation, optionalOldRotation ) {

		super( editor );

		this.type = 'SetRotationCommand';
		this.name = 'Set Rotation';
		this.updatable = true;

		this.node = node;

		if ( node !== undefined && newRotation !== undefined ) {

			this.oldRotation = node.rotation;
			this.newRotation = newRotation;

		}

		if ( optionalOldRotation !== undefined ) {

			this.oldRotation = optionalOldRotation;

		}

	}

	execute() {

		this.node.rotation = this.newRotation
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	undo() {

		this.node.rotation = this.oldRotation;
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	update( command ) {

		this.newRotation = command.newRotation

	}

	toJSON() {

		const output = super.toJSON( this );

		output.objectUuid = this.object.uuid;
		output.oldRotation = this.oldRotation.toArray();
		output.newRotation = this.newRotation.toArray();

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.object = this.editor.objectByUuid( json.objectUuid );
		this.oldRotation = new Euler().fromArray( json.oldRotation );
		this.newRotation = new Euler().fromArray( json.newRotation );

	}

}

export { SetRotationCommand };
