#include "generateCode.h"
#include "header.h"
#include "singleFunctions/singleFunctions.h" 
#include "stringFunction.h"
#include <cstdlib>

std::string generateFileName(char *filename) {
  std::string ret{};
  unsigned int i{};
  while (filename[i] != '.') {
    ret += filename[i];
    i++;
  }
  ret += ".asm";
  return ret;
}

void generatePrintfCode(std::ofstream *file) {
  *file << "\n\n";
  *file << "_printf:\n";
  *file << "\tmov rax, 1\n";
  *file << "\tmov rdi, 1\n";
  *file << "\tsyscall\n";
  *file << "\tret\n";
}

void generateScanfCode(std::ofstream *file) {
  *file << "\n\n";
  *file << "_scanf:\n";
  *file << "\tmov rax, 0\n";
  *file << "\tmov rdi, 0\n";
  *file << "syscall\n";
  *file << "\tret\n";
}

void generateBaseCode(std::ofstream *file) {
  *file << "section .text\n";
  *file << "global _start";
  
  for (InstrucType &value : generateFunction) {
    switch(value) {
      case __printf__:
        generatePrintfCode(file);
        break;
      case __scanf__:
        generateScanfCode(file);
        break;
      default:
        break;
    }
  }
  
  *file << "\n";
  *file << "_start:\n";
}

void generateExitCode(std::string _ExitValue, std::ofstream *file) {
  *file << "\n";
  *file << "\tmov rax, 60\n";
  *file << "\tmov rdi, " << _ExitValue << "\n";
  *file << "\tsyscall\n";
}

std::vector<std::string> seperateString(std::string _Value) {
  std::vector<std::string> ret{};
  std::string tmp{};
  for (char &c : _Value) {
    if (c == '\n') {
      tmp += c;
      ret.push_back(tmp);
      tmp = "";
    }
    else { 
      tmp += c;
    }
  }
  return ret;
}

void generatePrintfCall(std::string _PrintValue, std::ofstream *file, 
                       unsigned int *_Pos, std::vector<DataSection> *data, 
                       TokenValue _Type) {
  if (si::find(&_PrintValue, '\n') != 0) {
        
    // make a loop (ones i leaned how to)
    std::vector<std::string> strSep{ seperateString(_PrintValue) };
    for (std::string &str : strSep) {
      DataSection tmp(str, _Type);
      data->push_back(tmp);
      *file << "\n";
      *file << "\tmov rsi, str" << *_Pos << "\n";
      //*file << "\tadd rsi, 0xA\n";
      *file << "\tmov rdx, "; 
      *file << str.length() << "\n"; 
      *file << "\tcall _printf\n";   
      (*_Pos)++;
    }
    
  } 
  else {
    DataSection tmp(_PrintValue, _Type);
    data->push_back(tmp);
    *file << "\n";
    *file << "\tmov rsi, str" << *_Pos << "\n";
    *file << "\tmov rdx, " << _PrintValue.length() << "\n";
    *file << "\tcall _printf\n";
    (*_Pos)++;
  }
}

void generateDataSection(std::ofstream *file, 
                         std::vector<DataSection> *data) {
  *file << "\n";
  *file << "section .data\n";

  unsigned int count{};
  for (DataSection value : *data) {
    if (si::find(&value._Value, '\n')) {
      *file << "\tstr" << count << ": db \""; 
      *file << value._Value.substr(0, (value._Value.length() - 1)) << "\", 0xA\n"; 
    }
    else {
      *file << "\tstr" << count << ": db \"" << value._Value << "\"\n"; 
    }
    count++;
  } 
}

void generateCode(std::vector<Instruction> *_Instruc, char *filename,
                  std::string _Flags) {
  std::string fileName = generateFileName(filename);
  std::vector<DataSection> variableDeclaration{};
  unsigned int pos{};
  std::ofstream file(fileName);

  generateBaseCode(&file);
  
  for (Instruction &value : *_Instruc) {
    switch(value._Type) {
      case __function__:
      break;
      case __variable__:
      break;
      case __exit__:
        generateExitCode(value._Value[0], &file);
        break;
      case __printf__:
        generatePrintfCall(value._Value[0], &file, &pos, 
                           &variableDeclaration, value._VecList[2]);
        break;
      case __scanf__:
        //generateScanfCall(value._Value[0])
      break;
      default:
        printError("Try to reinstall the programm", 1);
        break;
      pos++;
    }
  }

  generateDataSection(&file, &variableDeclaration);

  file.close();

  std::string fileNameNoExtension{ fileName.substr(0, fileName.find_last_of('.')) };
  std::string compileFile{ 
    "nasm -f elf64 -o build/" + fileNameNoExtension + ".o " + fileName };
  std::string linkFile{ 
    "ld -o build/" + fileNameNoExtension + " build/" + fileNameNoExtension + ".o" };
  std::string removeDotAsmFile{ "rm " + fileName };
  std::string removeDotOFile{ "rm build/" + fileNameNoExtension + ".o" };
  

  system(compileFile.c_str());
  system(linkFile.c_str());
  system(removeDotOFile.c_str());

  if (_Flags != "-s") {
    system(removeDotAsmFile.c_str());
  }
}
