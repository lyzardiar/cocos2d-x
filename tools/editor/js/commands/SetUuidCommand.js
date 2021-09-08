import { Command } from '../Command.js';

/**
 * @param editor Editor
 * @param node cc.Node
 * @param newUuid string
 * @constructor
 */
class SetUuidCommand extends Command {

	constructor( editor, node, newUuid ) {

		super( editor );

		this.type = 'SetUuidCommand';
		this.name = 'Update UUID';

		this.node = node;

		this.oldUuid = node ? node.uuid : undefined;
		this.newUuid = newUuid;

	}

	execute() {

		this.node.uuid = this.newUuid;
		this.editor.signals.nodeChanged.dispatch( this.node );
		this.editor.signals.sceneGraphChanged.dispatch();

	}

	undo() {

		this.node.uuid = this.oldUuid;
		this.editor.signals.nodeChanged.dispatch( this.node );
		this.editor.signals.sceneGraphChanged.dispatch();

	}

	toJSON() {

		const output = super.toJSON( this );

		output.oldUuid = this.oldUuid;
		output.newUuid = this.newUuid;

		return output;

	}

	fromJSON( json ) {

		super.fromJSON( json );

		this.oldUuid = json.oldUuid;
		this.newUuid = json.newUuid;
		this.node = this.editor.nodeByUuid( json.oldUuid );

		if ( !this.node ) {

			this.node = this.editor.nodeByUuid( json.newUuid );

		}

	}

}

export { SetUuidCommand };
