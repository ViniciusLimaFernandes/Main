#include<fstream>

void importData(int id_func, string nome_user, string nickname, string dtadmissao, double salario_func){
    ofstream file;
    file.open ("dadosfuncionarios.txt");
    //Iniciar laco for aqui para upar dados
    file << id_func << nome_user << nickname << dtadmissao << salario_func << endl;
    //finalizar laco for aqui para upar dados
    file.close();
}

void exportData(){
    //double fDouble;
	//int fInt;
	string fString[3];
	
	ifstream myfile;
	string fileLocation;

	//gets file location from the user
	cout << "Please enter the location of the file: ";
	getline(cin, fileLocation);
	
	//opens the file
	myfile.open(fileLocation);

	//makes sure that the file opened properly
	while(myfile.fail())
	{
		cout << "The file at location " << fileLocation << " failed to open" << endl;
		cout << "Please enter the location of the file: ";
		getline(cin, fileLocation);
		myfile.open(fileLocation);
	}

	//extracts data from the file
    for(int i = 0; i<3; i++){
        myfile >> fString[i];
    }

	//outputs data to the screen
    for(int i = 0; i<3; i++){
        cout << endl << fString[i];
    }
  

	cin.ignore();
}