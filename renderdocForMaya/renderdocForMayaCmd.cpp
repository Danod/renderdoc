#include <maya/MPxCommand.h>
#include <maya/MFnPlugin.h>

#include <Windows.h>

class renderdocForMaya : public MPxCommand
{
public:
	renderdocForMaya();
	virtual ~renderdocForMaya();

	static void* creator();

	virtual MStatus doIt ( const MArgList& args );

};

renderdocForMaya::renderdocForMaya()
{
}

renderdocForMaya::~renderdocForMaya() 
{
}

MStatus renderdocForMaya::doIt( const MArgList& args )
{
	MStatus stat = MS::kSuccess;

	setResult( "renderdocForMaya command executed!\n" );

	return stat;
}

void* renderdocForMaya::creator()
{
	return new renderdocForMaya();
}

MStatus initializePlugin( MObject obj )
{
	MFnPlugin plugin( obj, PLUGIN_COMPANY, "1.0", "Any");

	MStatus status = plugin.registerCommand( "renderdoc",
		renderdocForMaya::creator );
	if (!status) 
		status.perror("registerCommand");

	printf("renderdocForMaya!initializePlugin: loading renderdoc.dll\n");
	LoadLibrary("renderdoc.dll");

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MFnPlugin plugin( obj );

	MStatus status = plugin.deregisterCommand( "renderdoc" );
	if (!status) 
		status.perror("deregisterCommand");

	return status;
}
