#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<math.h>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;

typedef map<string,int> stringmap;

static string removeSymbol(string str){
	size_t l=str.size();
    for (size_t i=0; i<l; i++){
        if (ispunct(str[i])){ //checks if the given character is a punctuation character or not
        	str[i] = ' ';
        }
    }
	return str;
}

void frequance(istream &file, stringmap &map){
    string s, word;
    bool exist;
    stringmap::iterator  it=map.begin();
	while(!file.eof()){
		file >> s; //read from the file word by word
		transform(s.begin(), s.end(), s.begin(), ::tolower); // using transform() function and ::tolower in STL to convert a whole string to lowercase
		//transform : Performs a transformation on given array/string.
		s=removeSymbol(s); // function to remove symbpol from a string
		istringstream iss(s);
        //string word;
        while(iss >> word) {//whene we ingnor or replace symbol by space It will produce one or more words
        	exist=false;
		    it=map.begin();
		    while(exist==false && it!=map.end()){
            	if(map.find(word)!=map.end()){
    	        	exist=true;
            		map[word]=it->second+1;
		        }
	    	    it++;
    	    }
           if(exist==false){
                map.insert(make_pair(word,1));
            }
        }
	}
}

int inner_product(stringmap map1, stringmap map2){
    int dotproduct = 0;
    for (stringmap::iterator p1 = map1.begin(); p1 != map1.end(); p1++){
        for (stringmap::iterator p2 = map2.begin(); p2 != map2.end(); p2++){
            if (p1->first == p2->first)
                dotproduct += (p1->second*p2->second);
        }
    }
    return dotproduct;
}


 double Euclidean_norm(stringmap map){ //The Euclidean norm of the frequency vector is defined by ||D||=sqrt[ pow(freq1,2)+pow(freq2,2)+...]
	double i=0;
	for(stringmap::iterator  p = map.begin(); p !=map.end(); p++){
		i +=pow(p->second,2);
	}
	i=sqrt(i);
	return i;
 }


 /*

 float cosine_similarity(const std::map<int,float> & A,const std::map<int,float> & B)
{
    float dot = 0.0, denom_a = 0.0, denom_b = 0.0 ;
    for(auto &a:A)
    {
      denom_a += a.second * a.second ;
    }

    for(auto &b:B)
    {
      denom_b += b.second * b.second ;
    }

    for(auto &a:A)
    {
        if(B.find(a.first) != B.end())
        {
          dot +=  a.second * B.find(a.first)->second ;
        }
    }
    return dot / (sqrt(denom_a) * sqrt(denom_b)) ;
}

 */






int main(){
	ifstream file1,file2;
    double dotproduct;
    double nbr1, nbr2;
    double pro;
    float distance;
	stringmap map1,map2;
    cout << "\t/====================================\\" << endl;
	cout << "\t|   The document distance problem    |" << endl;
	cout << "\t\\=================================== /" << endl << endl;



  string pathFile1 , pathFile2;
    cout << "\t============================ \\" << endl;
    cout << "\t============================ \\ " << endl;
    cout << "|||| read the Two Files |||| " << endl ;
    cout << "\t============================ \\" << endl;
    cout << "\t============================ \\ " << endl;
    cout << "\n \n ";

    cout << "Put the path of the first txt file :  " << endl ;
    cin >> file1;
    cout << "\n " << endl ;
    cout << "Put the path of the secende txt file :  " << endl ;
    cin >> file2;
    cout << "\n " << endl ;



    if (!file1)
        std::cout << "file 1 error" << endl;
    if (!file2)
        std::cout << "file 2 error" << endl;

    frequance(file1, map1);
    frequance(file2, map2);
    cout << "Frequency vector for file 1" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "+       word         |      frequance      +" << endl;
    cout << "+------------------------------------------+" << endl;
    for (stringmap::iterator it = map1.begin(); it != map1.end() ; it++){
        cout << "|       " << it->first << "          ::        " << it->second << "           " << endl;
    }
    cout << "+------------------------------------------+" << endl;
    cout << endl;
    cout << "Frequency vector for file 2" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "+       word         |      frequance      +" << endl;
    cout << "+------------------------------------------+" << endl;
    for (stringmap::iterator it2 = map2.begin(); it2 != map2.end(); it2++){
        cout << "|       " << it2->first << "          ::        " << it2->second << "           " << endl;
    }
    cout << "+------------------------------------------+" << endl;

    dotproduct = inner_product(map1, map2);
    cout << "the dot product of the tow vectors is :" << dotproduct << endl;

    nbr1 = Euclidean_norm(map1);
    nbr2 = Euclidean_norm(map2);
    pro = nbr1*nbr2;

    distance =dotproduct / pro;
    double res=acos(distance)*180/3.14;//we use *180/3.14 to convert result into degrees


    cout << "The distance between the docments is " << res << endl;
    cout << endl;
    cout << "--------------------------------------------------------" <<endl;
    if(res==0){
    	cout << "              The two files are the same              " << endl;
	}else if(res>0 && res<=61){
		cout << " The tow files have more similarities than differences" << endl;
	}else if (res>60 && res<90){
		cout << " The tow files have more differences than similarities" << endl;
	}else if(res>=90){
		cout << "        The two files are completely different        " << endl;
	}
     cout << "the similarity is "<< res*100<<"% ------------------------------------------------------" <<endl;
}
Write to Islem Ibrahim Heraoui
