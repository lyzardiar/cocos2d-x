import { Command } from '../Command.js';

/**
 * @param editor Editor
 * @param node cc.Node
 * @param newTexture cc.Texture2D
 * @constructor
 */
class SetTextureCommand extends Command {

	constructor( editor, node, newTexture ) {

		super( editor );

		this.type = 'SetTextureCommand';
		this.name = 'Set Texture';
		
		this.node = node;

		if ( node !== undefined && newTexture !== undefined ) {

			this.oldTexture = node.getTexture()
      this.oldTexture.retain()
			this.newTexture = newTexture
      this.newTexture.retain()
      this.oldTextureRect = node.getTextureRect()
		}
	}

	execute() {
    this.node.setTexture(this.newTexture)
    this.node.setTextureRect({origin: {x: 0, y: 0}, size: this.newTexture.getContentSize()})
		this.editor.signals.nodeChanged.dispatch( this.node );
	}

	undo() {
		this.node.setTexture(this.oldTexture)
    this.node.setTextureRect(this.oldTextureRect)
		this.editor.signals.nodeChanged.dispatch( this.node );
	}

	toJSON() {

		const output = super.toJSON( this );
		return output;

	}

	fromJSON( json ) {
		super.fromJSON( json );
	}

  dispose() {
		super.dispose();

    if (this.oldTexture) {
      this.oldTexture.release()
    }

    if (this.newTexture) {
      this.newTexture.release()
    }
	}

}

export { SetTextureCommand };
