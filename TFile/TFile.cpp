/*
Julián Jiménez González
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdlib>		//malloc-atoi
#include "TFile.h"

TFile::TFile(const char * fileName) {
	this->m_fileName = fileName;		//con esto se evita que cada vez que se abra el archivo desde main(), haya que pasarle el nombre, que es el mismo porque
}										//se da por hecho que no es lógico (conceptualmente) crear 1 sólo objeto TFile para varios archivos distintos

unsigned int TFile::openFile(const char * fileMode) {
	fopen_s(&this->m_file, this->m_fileName, fileMode);

	return reinterpret_cast<unsigned int>(this->m_file);
}

int TFile::closeFile() {			//fclose puede devolver EOF (=-1)
	return fclose(this->m_file);
}

unsigned int TFile::readFile(const short int numCharToRead, char * buffer) {
	return fread(buffer, sizeof(*buffer), static_cast<size_t>(numCharToRead), this->m_file);
}

unsigned int TFile::writeFile(const short int numCharToWrite, char * buffer) {
	return fwrite(buffer, sizeof(*buffer), static_cast<size_t>(numCharToWrite), this->m_file);
}

short int TFile::fileSize() {			//también se podría gestionar con una variable miembro privada
	fseek(this->m_file, 0, SEEK_END);

	short int numChars = static_cast<short int>(ftell(this->m_file));

	fseek(this->m_file, 0, SEEK_SET);

	return numChars;
}