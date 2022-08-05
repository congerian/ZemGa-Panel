#include "./util.hxx"

#include <QtCore>

QString fileToBase64 ( QString source ) 
{
    QFile sourceFile ( source );
    sourceFile.open ( QIODevice::ReadOnly );        

    QByteArray base64Encoded  = sourceFile.readAll().toBase64();  

    return base64Encoded;
}