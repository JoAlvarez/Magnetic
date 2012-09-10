#ifndef __TOOL_FILE_WRITER_H__
#define __TOOL_FILE_WRITER_H__

#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class ToolFileWriter
{
    private:
        vector< vector< string > >  lines;
        string                      writeTo;

        static                      ToolFileWriter* toolFileWriterInstance;
        static                      int toolFileWriterReferenceCount;

    public:
        static                      ToolFileWriter* getInstance();
        void                        release();
        void                        setWriteFile( string fileName );
        string                      intToString( int integer );
        string                      doubleToString( double floatingPoint );
        string                      boolToString( bool boolean );
        void                        addLine( vector< string > line );
        void                        write();
};

#endif
