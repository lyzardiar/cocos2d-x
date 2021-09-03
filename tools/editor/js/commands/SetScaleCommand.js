import { Command } from '../Command.js';
import { Vector3 } from '../libs/three.module.js';

/**
 * @param editor Editor
 * @param object THREE.Object3D
 * @param newScale THREE.Vector3
 * @param optionalOldScale THREE.Vector3
 * @constructor
 */
class SetScaleCommand extends Command {

	constructor( editor, node, newScale, optionalOldScale ) {

		super( editor );

		this.type = 'SetScaleCommand';
		this.name = 'Set Scale';
		this.updatable = true;

		this.node = node;

		if ( node !== undefined && newScale !== undefined ) {

			this.oldScale = {x: node.scaleX, y: node.scaleY}
			this.newScale = Object.assign({}, newScale)

		}

		if ( optionalOldScale !== undefined ) {

			this.oldScale = Object.assign({}, optionalOldScale)

		}

	}

	execute() {
		this.node.scaleX = this.newScale.x
		this.node.scaleY = this.newScale.y
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	undo() {

		this.node.scaleX = this.oldScale.x
		this.node.scaleY = this.oldScale.y
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	update( command ) {
		Object.assign(this.newScale, command.newScale)
	}

	toJSON() {

		const output = super.toJSON( this );

		output.objectUuid = this.object.uuid;
		output.oldScale = this.oldScale.toArray();
		output.newScale = this.newScale.toArray();

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.object = this.editor.objectByUuid( json.objectUuid );
		this.oldScale = new Vector3().fromArray( json.oldScale );
		this.newScale = new Vector3().fromArray( json.newScale );

	}

}

export { SetScaleCommand };
