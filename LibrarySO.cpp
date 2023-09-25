#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

//String agr é st
typedef std::string st;
//Map agr é Dict
typedef std::map<int, st> dict;
//fstream agr é fs
    typedef std::fstream fs;

class MainDictionary{
    public:
    dict di;
    File write;

    //Comandos. Nn sei se fiz certo o args[], mas tá aí
    int Main(int argc, char** argv){
        MainDictionary data;
        Show debug;
        File write;

        if(std::strcmp(argv[1], "MainDictionary") == 0){
            if(std::strcmp(argv[2], "--insert") == 0){
                data.Insert(std::atoi(argv[3]), (argv[4]));
            }
            else if(std::strcmp(argv[2], "--remove") == 0){
                data.Remove(std::atoi(argv[3]));
            }
            else if(std::strcmp(argv[2], "--update") == 0){
                data.Update(argv[3], argv[4]);
                debug.DisplayDic(data.di);
            }
            else if(std::strcmp(argv[2], "--search") == 0){
                data.Search(std::atoi(argv[3]));
            }
        }
        return 0;
    }

    //--insert
    void Insert(int key, st translate){
        di.insert(std::pair<int, st>(key, translate));
        std::cout << "key: " << key << "means: " << translate << '\n';
        write.WriteInFile(di);
    }

    //--remove
    void Remove(int key){
        auto i = di.begin();
        for(; i != di.end();){
            //Não faço IDEIA do pq isso nn funciona @_@ / Vou me matar 💀💀💀
            if(i == key){
                i = di.erase(i);
                write.EraseInFile();
                write.WriteInFile(di);
                std::cout << "--REMOVED--" << '\n';
            }
            i++;
        }
    }

    //--update
    void Update(st takeOff, st putOn){
        //Não faço a menor ideia doq seja const int* mas o bgl tava bugado sem isso 🤷‍♂️
        auto i = di.begin();
        const int *place = &(i -> first);
        for(;i != di.end();){
            if(i -> second == takeOff){
                i = di.erase(i);
                di.insert(std::pair<int, st>(*place, putOn));
                write.EraseInFile();
                write.WriteInFile(di);
                std::cout << "--SWITCHED--" << 'n';
            }
        }
    }

    bool Search(int key){
        auto i = di.begin();
        for(;i != di.end();){
            //Aqui denovo, msm erro ;-; eu to lgd q é pq eu to usano ponteiro com int (?) mas eu nn sei como arrumar.
            if(i -> second == key){
                return true;
            }
            i++;
        }
        return false;
    }
};

class File{
    
    public:
    fs mainFile;

    //Abre o arquivo, escreve a chave e o valor no dicionário e fecha
    void WriteInFile(dict di){
        mainFile.open("MainFile.txt", std::ios::out);
        for(auto pair :  di){
            mainFile << pair.first << " - " << pair.second << '\n';
        }
        mainFile.close();
    }
    //Deleta todas as informações do arquivo
    void EraseInFile(){
        mainFile.open("MainFile.txt", std::ios::out);
        mainFile.clear();
        mainFile.close();
    }
};

class Show{
    public:

    void DisplayDic(dict di){
        for(auto pair : di){
            std::cout << pair.first << " - " << pair.second << '\n';
        }
    }
};
