/*
Julián Jiménez González
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <cstdlib>		//malloc-atoi
#include "TFile.h"

TFile::TFile(const char * fileName) {
	this->m_fileName = fileName;		//con esto se evita que cada vez que se abra el archivo desde main(), haya que pasarle el nombre, que es el mismo porque
										//se da por hecho que no es lógico (conceptualmente) crear 1 sólo objeto TFile para varios archivos distintos
	this->fileOpened = false;
}

unsigned int TFile::openFile(const char * fileMode) {
	if (!this->fileOpened) {
		fopen_s(&this->m_file, this->m_fileName, fileMode);
		this->fileOpened = true;
		return reinterpret_cast<unsigned int>(this->m_file);
	} else
		return 0;
}

int TFile::closeFile() {
	if (this->fileOpened) {
		this->fileOpened = false;
		return fclose(this->m_file);
	} else
		return 1;
}

unsigned int TFile::readFile(const short int numCharToRead, char * buffer) {
	if (this->fileOpened)
		return fread(buffer, sizeof(*buffer), static_cast<size_t>(numCharToRead), this->m_file);
	else
		return 0;
}

unsigned int TFile::writeFile(const short int numCharToWrite, char * buffer) {
	if (this->fileOpened)
		return fwrite(buffer, sizeof(*buffer), static_cast<size_t>(numCharToWrite), this->m_file);
	else
		return 0;
}

short int TFile::fileSize() {
	if (this->fileOpened) {
		fseek(this->m_file, 0, SEEK_SET);

		fseek(this->m_file, 0, SEEK_END);

		short int numChars = static_cast<short int>(ftell(this->m_file));

		fseek(this->m_file, 0, SEEK_SET);

		return numChars;
	} else
		return 0;
}

TFile::~TFile() {
	if (this->fileOpened) {
		this->closeFile();
	}
}