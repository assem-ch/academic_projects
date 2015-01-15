package pack;







public class Table_Quad {

	Table_Quad()
	{
		Courant=0;
		Table=new Quad[100];
		tempCourant=0;
		
	}
	
	
public class Quad
{
	Quad(){
			operation=new String("");
			operator1=new String("");
			operator2=new String("");
			result=new String("");
	}
	
	
	
	String operation;
	String operator1;
	String operator2;
	String result;
	
	
}

	
	public int  UpdateParam(String param,String val)
	{ int cpt=0;
		for(Quad S:Table)

		{if (S!=null) {if (param.compareTo(S.operation)==0) {S.operation=val;cpt++;}	
		 if (param.compareTo(S.operator1)==0) {S.operator1=val;cpt++;}	
		 if (param.compareTo(S.operator2)==0) {S.operator2=val;cpt++;}	
		 if (param.compareTo(S.result)==0) {S.result=val;cpt++;}	
		}}
		return cpt;
	}
	
	
	

	
public Quad[] Table;
private int Courant;
private int tempCourant;

public int genereQuad(String operation,String operator1,String operator2,String result)
{
	Quad temp=new Quad();
	temp.operation=operation;
	temp.operator1=operator1;
	temp.operator2=operator2;
	temp.result=result;
	
	Table[Courant]=temp;
	
	
	int save=Courant;
	Courant++;
	
	return save;
	
}

public void modifyQuad(int index,int champ,String val)
{	switch (champ)
	{case 1:Table[index].operation=val;break;
	 case 2:Table[index].operator1=val;break;	
	 case 3:Table[index].operator2=val;break;
	 case 4:Table[index].result=val;break;
	}
}

public String readQuad(int index,int champ)
{String val="";
	switch (champ)
	{case 1:val=Table[index].operation;break;
	 case 2:val=Table[index].operator1;break;	
	 case 3:val=Table[index].operator2;break;
	 case 4:val=Table[index].result;break;
	}
	return val;
}

public String NewTemp()
{   int save=tempCourant;

	tempCourant++;
return "tmp"+save;

}

public String ToString()
{	String temp=new String();
	
	temp+="Table de Quads:\n";
	temp+="operation\top1\top2\tresult\n";
	for (Quad S : Table) {if (S!=null) temp+=S.operation+"\t"+S.operator1+"\t"+S.operator2+"\t"+S.result+"\n";								
						}

	temp+="-------------------------------------------------------------";
	return temp;
}	

public String ToHTML()
{	String temp=new String();int cpt=0;
temp+="<h3><font color=\"green\"><u>Table de Quads:</u></font></b>";
	temp+="<table bgcolor=\"#ccFF33\" border=\"2\" cellpadding=\"3\" cellspacing=\"2\">";
	temp+="<tr><th>Num</th><th>operation</th><th>op1</th><th>op2</th><th>result</th></tr>";
	for (Quad S : Table) {if (S!=null) temp+="<tr><th>"+(cpt++)+"</th><th>"+S.operation+"</th><th>"+S.operator1+"</th><th>"+S.operator2+"</th><th>"+S.result+"</th></tr>";								
						}
		temp+="</table>";

	return temp;
}

public int getCourant() {
	return Courant;
}

}
