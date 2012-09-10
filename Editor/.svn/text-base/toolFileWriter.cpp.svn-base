#include "toolFileWriter.h"
#define FILE_COLUMN_WIDTH 15

ToolFileWriter* ToolFileWriter::toolFileWriterInstance = NULL;
int ToolFileWriter::toolFileWriterReferenceCount = 0;

ToolFileWriter* ToolFileWriter::getInstance()
{
    if( !toolFileWriterInstance )
        toolFileWriterInstance = new ToolFileWriter();

    toolFileWriterReferenceCount++;
    return toolFileWriterInstance;
}

void ToolFileWriter::release()
{
    if( --toolFileWriterReferenceCount <= 0 &&  toolFileWriterInstance )
        delete toolFileWriterInstance;

    if( toolFileWriterReferenceCount < 0 )
        toolFileWriterReferenceCount = 0;
}

void ToolFileWriter::setWriteFile( string fileName )
{
    writeTo = fileName;
}

string ToolFileWriter::intToString( int integer )
{
    stringstream temp;
    string temp2;
    temp << integer;
    temp >> temp2;
    return temp2;
}

string ToolFileWriter::doubleToString( double floatingPoint )
{
    stringstream temp;
    string temp2;
    temp << floatingPoint;
    temp >> temp2;
    return temp2;
}

string ToolFileWriter::boolToString( bool boolean )
{
    if( boolean )
        return "1";
    return "0";
}

void ToolFileWriter::addLine( vector< string > line )
{
    lines.push_back( line );
}

void ToolFileWriter::write()
{
    ofstream writeFile( writeTo.c_str() );
        for( int i = 0; i < lines.size(); ++i )
        {
            for( int j = 0; j < lines[ i ].size(); ++j )
                writeFile << setw( FILE_COLUMN_WIDTH ) << left << lines[ i ][ j ];
            writeFile << "\n";
        }
    writeFile.close();

    //Clear vector for next write cycle
    for( int i = 0; i < lines.size(); ++i )
        lines[ i ].clear();
    lines.clear();

}
