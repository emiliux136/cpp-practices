#include <iostream>
#include <fstream>  //para inFile.
#include <string>

std::string readFile(const std::string &filename)
{
    std::ifstream inFile(filename); // crea un objeto "std::ifstream" para abrir un archivo en modo lectura.
    
    if (!inFile)
    {
        std::cerr << "Error opening the file" << filename << std::endl;
        return "";
    }
    std ::string content;
    std::string line;
    while(getline(inFile, line))
    {
        content += line + "\n";
    }
    inFile.close(); // no es necesario cerrarlo, por el destructor de std::ifstream, pero es buena práctica.
    return content;
}

std::string replaceStr(const std::string &original, const std::string &s1, const std::string &s2)
{
    std::string replaced;
    size_t pos = 0;
    size_t found = original.find(s1); // find(s1) busca la primera aparición de la cadena s1 dentro de original

    while (found != std::string::npos) // El bucle se ejecuta mientras haya ocurrencias de s1 en original
    {    
        replaced.append(original, pos, found - pos);
        replaced.append(s2);
        pos = found + s1.length(); //Avanza la posición saltandose la ocurrencia de s1 que ya fue reemplazada
        found = original.find(s1, pos); //Busca la siguiente aparición de s1
    }
    replaced.append(original, pos, original.length() - pos);
    return replaced;
}

void myreplace(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::string original = readFile(filename);

    if (original.empty())
        return;
    std::string replaced = replaceStr(original, s1, s2);
    std::string newFile = filename + ".replace";
    std::ofstream outStream(newFile); // abre un archivo para escribir datos y si no existe, se crea
    if(!outStream)
    {
        std::cerr << "Error creating output file: " << newFile << std::endl;
        return;
    }
    outStream << replaced;
    outStream.close();
    std::cout << "replacement completed! Output file: " << newFile << std::endl;

}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Propper use: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    myreplace(filename, s1, s2);
}