import { UITabbedPanel } from './libs/ui.js';

import { SidebarNode } from './Sidebar.Node.js';

function SidebarProperties( editor ) {

	var strings = editor.strings;

	var container = new UITabbedPanel();
	container.setId( 'properties' );

	container.addTab( 'node', strings.getKey( 'sidebar/properties/node' ), new SidebarNode( editor ) );
	container.select( 'node' );

	return container;

}

export { SidebarProperties };
