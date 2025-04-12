#include <iostream>
using namespace std;

class clsBase
{
private:
	void PrivateFonct()
	{
		cout << "\nHi,I'm Private Fonction .";
	}
protected:
	void ProtectedFonct()
	{
		cout << "\nHi,I'm Protected Fontion .";
	}
public:
	void PublicFonct()
	{
		cout << "\nHi,I'm Public Fonction .";
	}
};

class clsPrivateInheritance : private clsBase
{
public:
	void InheritanceFont1()
	{ 
	clsBase::PublicFonct();
	//clsBase::PrivateFonct(); not heritance
	clsBase::ProtectedFonct();
	}
};
class clsPretectedInheritance : protected clsBase
{
public:
	void InheritanceFont2()
	{
		clsBase::PublicFonct();
		//clsBase::PrivateFonct(); not heritance
		clsBase::ProtectedFonct();
	}
};
class clsPublicInheritance : public clsBase
{
public:
	void InheritanceFont3()
	{
		clsBase::PublicFonct();
		//clsBase::PrivateFonct(); not heritance
		clsBase::ProtectedFonct();
	}
};

void ApplicationInheritance()
{
	clsPublicInheritance Ob1;
	Ob1.PublicFonct();
	clsPretectedInheritance Ob2;
	//not ob access
	clsPrivateInheritance Ob3;
	//not ob access 
}

class clsPerson
{
public:
	 virtual void Print()
	{
		cout << "\nHi I'm the person fonction .";
	}
};
class clsEmployee : public clsPerson
{
public:
	void Print()
	{
		cout << "\nHi I'm the Employee fonction .";
	}
};
class clsStudent : public clsPerson
{
public:
	void Print()
	{
		cout << "\nHi I'm the student fonction .";
	}
};

void ApplicationUpCastingAndVirtualFct()
{
	clsEmployee Employee1;
	clsStudent Student1;
	//Early or static Binding.
	Employee1.Print();
	Student1.Print();
	//Late or dynamin Binding.
	clsPerson* Person2 = &Employee1;
	clsPerson* Person3 = &Student1;
	Person2->Print();
	Person3->Print();
	//Upcasting : Derived to Base .
	clsStudent S;
	clsPerson* P = &S;
	P->Print();
}

//Abstract Fontion / interface / Constract .
class clsMobile
{
	virtual void Diel(int MobilePhone) = 0;
	virtual void SendSMS(int MobilePone, string SMS) =0;
	virtual void TakePicture() = 0;
	// Fonctions Without Implementation .
};
class clsIphone : public clsMobile
{
public:
	void Diel(int MobilePhone)
	{

	}
	void SendSMS(int MobilePone, string SMS)
	{

	}
	void TakePicture() 
	{

	}
};
class clsSumsungNote10 : public clsMobile
{

};

void ApplicationAbstractFonctionOrInterface()
{
	clsIphone Iphone;
	Iphone.Diel(1234);
	//we can not define a object from class sum without doing the implmentation.
	// clsSumsungNote10 Sum ; Wrong !!
}

//Friend Class and Friend Fonction :
class clsA
{
private:
	int _Var2;
protected:
	int _Var3;
public:
	int Var1;

	clsA()
	{
		 Var1 = 10;
		_Var2 = 20;
		_Var3 = 30;
	}

	friend class clsB; //This is Friend Class . B Payed a Barbery to A :-) .
	friend int SumOfVariables(clsA A); // This is Friend Fonction .
};
class clsB
{
public:
	void SumVariable(clsA Obj)
	{
		cout << "\nSum = "
			<< Obj.Var1 + Obj._Var2 + Obj._Var3;
	}
};
int SumOfVariables(clsA A)
{
	return A.Var1 + A._Var2 + A._Var3;
}
int SumOfVariables2(clsA A)
{
	return A.Var1; // We can only access to pub variable inside the fct.
}

void ApplicationFriendFonction()
{
	clsA A;
	clsB B;
	A.Var1;
	B.SumVariable(A);
}

//Structur Inside Class :
class clsPerson2
{
	struct sAddress
	{
		string Address1;
		string Address2;
		string Country;
		string City;
	};
public:
	string FullName;
	sAddress Address;

	clsPerson2()
	{
		FullName = "Mohamed Benlajdid";
		Address.Address1 = "Agadir,Inzgan Ait Melloul";
		Address.Address2 = "Azrou,Duar Adi street";
		Address.Country = "Morocco";
		Address.City = "Agadir";
	}
	void PrintInformation()
	{
		cout << "\nFull Name : " << FullName;
		cout << "\nAddress1  : " << Address.Address1;
		cout << "\nAddress2  : " << Address.Address2;
		cout << "\nCountry   : " << Address.Country;
		cout << "\nCity      : " << Address.City;
	}
};

//Class instead class : Exemple .
class clsStudent2
{
	string _FullName;
	class clsResult
	{
	private:
		short _Mark1;
		short _Mark2;
		short _Mark3;
	public:
		clsResult(short Mark1,short Mark2,short Mark3)
		{
			_Mark1 = Mark1;
			_Mark2 = Mark2;
			_Mark3 = Mark3;
		}
		short AverageMark()
		{
			return (_Mark1 + _Mark2 + _Mark3)/3 ;

		}
		void SetMark1(short Mark1)
		{
			_Mark1 = Mark1;
		}
		short Mark1()
		{
			return _Mark1;
		}
		void SetMark2(short Mark2)
		{
			_Mark2 = Mark2;
		}
		short Mark2()
		{
			return _Mark2;
		}
		void SetMark3(short Mark3)
		{
			_Mark3 = Mark3;
		}
		short Mark3()
		{
			return _Mark3;
		}
		void ShowAllMarks()
		{
			cout << "\n\tShow All Marks : ";
			cout << "\nMark1 = " << _Mark1;
			cout << "\nMark2 = " << _Mark2;
			cout << "\nMark3 = " << _Mark3;
		}
	};
public:
	string SetFullName(string FullName)
	{
		_FullName = FullName;
	}
	string FullName()
	{
		return _FullName;
	}
	clsResult Result = clsResult(0, 0, 0);

	clsStudent2(string FullName, short M1, short M2, short M3)
	{
		_FullName = FullName;
		Result = clsResult(M1, M2, M3);
	}
};

void ApplicationOfInsteadClass()
{
	clsPerson2 Person;
	Person.PrintInformation();
	clsStudent2 Student("Mohamed Benlajdid", 18, 19, 18);
	Student.Result.ShowAllMarks();
	cout << endl;
	cout << Student.FullName() << endl;
	cout << Student.Result.AverageMark() << endl;
}

int main()
{

	system("pause>0");

}