import { Command } from '../Command.js';

/**
 * @param editor Editor
 * @param node cc.Node
 * @param attributeName string
 * @param newValue number, string, boolean
 * @constructor
 */
class SetValueCommand extends Command {

	constructor( editor, node, attributeName, newValue ) {

		super( editor );

		this.type = 'SetValueCommand';
		this.name = `Set ${attributeName}`;
		this.updatable = true;

		this.node = node;
		this.attributeName = attributeName;
		this.oldValue = ( node ) ? node[ attributeName ] : undefined;
		this.newValue = newValue;

	}

	execute() {

		this.node[ this.attributeName ] = this.newValue;
		this.editor.signals.nodeChanged.dispatch( this.node );
		// this.editor.signals.sceneGraphChanged.dispatch();

	}

	undo() {

		this.node[ this.attributeName ] = this.oldValue;
		this.editor.signals.nodeChanged.dispatch( this.node );
		// this.editor.signals.sceneGraphChanged.dispatch();

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

		this.attributeName = json.attributeName;
		this.oldValue = json.oldValue;
		this.newValue = json.newValue;
		this.node = this.editor.nodeByUuid( json.nodeUuid );

	}

}

export { SetValueCommand };
