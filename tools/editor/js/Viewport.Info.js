import { UIPanel, UIBreak, UIText } from './libs/ui.js';

function ViewportInfo( editor ) {

	var signals = editor.signals;
	var strings = editor.strings;

	var container = new UIPanel();
	container.setId( 'info' );
	container.setPosition( 'absolute' );
	container.setLeft( '10px' );
	container.setBottom( '10px' );
	container.setFontSize( '12px' );
	container.setColor( '#fff' );

	var verticesText = new UIText( '0' ).setMarginLeft( '6px' );
	var drawcallsText = new UIText( '0' ).setMarginLeft( '6px' );
	var frametimeText = new UIText( '0' ).setMarginLeft( '6px' );

	container.add( new UIText( strings.getKey( 'viewport/info/drawcalls' ) ).setTextTransform( 'lowercase' ) );
	container.add( drawcallsText, new UIBreak() );
	container.add( new UIText( strings.getKey( 'viewport/info/triangles' ) ).setTextTransform( 'lowercase' ) );
	container.add( verticesText, new UIBreak() );
	container.add( new UIText( strings.getKey( 'viewport/info/frametime' ) ).setTextTransform( 'lowercase' ) );
	container.add( frametimeText, new UIBreak() );

	signals.nodeAdded.add( update );
	signals.nodeRemoved.add( update );
	signals.geometryChanged.add( update );

	//

	function update() {
		var renderer = cc.director.getRenderer();
		
		verticesText.setValue( renderer.getDrawnVertices() );
		drawcallsText.setValue( renderer.getDrawnBatches() );
	}

	signals.sceneRendered.add( updateFrametime );

	function updateFrametime( frametime ) {

		frametimeText.setValue( Number( frametime ).toFixed( 2 ) + ' ms' );

	}

	return container;

}

export { ViewportInfo };
