import { Command } from '../Command.js';

/**
 * @param editor Editor
 * @param node cc.Node
 * @param attributeName string
 * @param newValue integer representing a hex color value
 * @constructor
 */
class SetColorCommand extends Command {

	constructor( editor, node, attributeName, newValue ) {

		super( editor );

		this.type = 'SetColorCommand';
		this.name = `Set ${attributeName}`;
		this.updatable = true;

		this.node = node;
		this.attributeName = attributeName;
		this.oldValue = ( node !== undefined ) ? this.node.getColor() : undefined;
		this.newValue = newValue;

	}

	execute() {

		this.node.setColor(cc.hexToColor(this.newValue));
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	undo() {

		this.node.setColor(this.oldValue);
		this.editor.signals.nodeChanged.dispatch( this.node );

	}

	update( cmd ) {

		this.newValue = cmd.newValue;

	}

	toJSON() {

		const output = super.toJSON( this );

		output.nodeUuid = this.node.uuid;
		output.attributeName = this.attributeName;
		output.oldValue = this.oldValue;
		output.newValue = this.newValue;

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.node = this.editor.nodeByUuid( json.nodeUuid );
		this.attributeName = json.attributeName;
		this.oldValue = json.oldValue;
		this.newValue = json.newValue;

	}

}

export { SetColorCommand };
