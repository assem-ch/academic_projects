package pack;

import pack.Symbole;


public class Table_symboles
{
	Table_symboles() {
					  Courant=0;
					  ownerCourant=new String("_GLOBAL_");
					  Table=new Symbole[100];
					  Log=new String("<h3><font color=\"green\"><u>Analyse Symantic</u></font></b>");
					 
					  cptERR=0;
					 }
	
	
public  Symbole[] Table;
private int Courant;
private String ownerCourant;
public String Log;
public Param Tpar=new Param();
public int cptERR;
public String SEscape="";


public class Param
{
    Param()
    {
    	paramCourant=0;
    	
    }
    
	private int paramCourant;
	
	public String NewParam()
	{   int save=paramCourant;

		paramCourant++;
	return "$"+save;

	}
	
	
	
	public int  UpdateParam(String param,String val)
	{ int cpt=0;
		for(Symbole S:Table)

		{if (S!=null) {if (param.compareTo(S.id)==0) {S.id=val;cpt++;}	
		 if (param.compareTo(S.type)==0) {S.type=val;cpt++;}	
		 if (param.compareTo(S.type2)==0) {S.type2=val;cpt++;}	
		 if (param.compareTo(S.val)==0) {S.val=val;cpt++;}	
		}}
		return cpt;
	}
	
	
	
	
}

public int getCourant() {
	return Courant;
}

public boolean search(String id,boolean warnning)  throws Exception 
{   boolean found=false;
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) found=true;	}
     
	 if (!found && warnning){Exception e=new Exception("call for inexistant identificater <b>&lt;"+id+"&gt;</b> a la ligne &lt;"+LexTests.nbLine+"&gt;");
							 
								throw e;
    	   
    	   						
       								}
     return found;
}

public int searchLine(String id)
{   int line=-1;
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) line=X.line;	}
     
	
     return line;
}

public String searchType(String id)
{   String type="unknown";
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) type=X.type;	}
     
	
     return type;
}



public String searchType2(String id)
{   String type2="unknown";
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) type2=X.type2;	}
     
	
     return type2;
}

public String getVal(String id)
{   String val="";
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) val=X.val;	}
     
	
     return val;
}

public void setVal(String id,String val)
{  
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) X.val=val;}
	 
	 }
     
	
  



public boolean verify_type(String id,String type) throws Exception 
{
	 boolean ok=false;
	 for (Symbole X : Table) {if (X!=null) if (X.id.compareTo(id)==0  && X.type.compareTo(type)==0 && (X.owner.compareTo(ownerCourant)==0 || X.owner.compareTo("_GLOBAL_")==0)) ok=true;	}
     
	 if (!ok){Exception e=new Exception("l'identificater <b>&lt;"+id+"&gt;</b>declaree a ligne <b>"+searchLine(id)+"</b> est de type <b>"+searchType(id)+"</b> n'est pas de type <b>"+type+"</br>");
							 
								throw e;
    	   
    	   						
       								}
     return ok;
	
	
	
}

public boolean declare(String id,String type,String type2,String val,int line)  throws Exception 
{  boolean done=false;
	 if (id.length()>30) {
		 Exception e=new Exception("identificater <b>&lt;"+id+"&gt;</b> declaree a ligne <b>&lt;"+searchLine(id)+"&gt;</b>  de longeur &lt;"+id.length()+"&gt; superiure a 30");
			throw e;
	 	}
	
else {
	boolean exist=search(id,false);
		
	if (!exist) {
		
		Symbole NEW=new Symbole();
		NEW.id=id;
		NEW.type=type;
		NEW.type2=type2;
		NEW.val=val;
		NEW.owner=ownerCourant;
		NEW.line=line;
		
		Table[Courant]=NEW;
		Courant++;
		
	}
	else {Exception e=new Exception("identificater &lt;"+id+"&gt; exist deja dans ligne &lt;"+searchLine(id)+"&gt; et redeclaree dans &lt;"+line+"&gt;");
	throw e;
			
				
	}
	done=!exist;
}
return done;
   
}
public void FinalTest() 
{
	for (Symbole S : Table) 
	{
		if (S!=null) {if (S.type=="label" && S.val.charAt(0)=='$') {
																			JoinInHtml(new Exception("l'etiqette de <b>"+S.id+"</b> n'est pas definie"));
		cptERR++;
		
		}
	
	
		
	}
	}
	
}


public String ToString()
{	
	String temp=new String();
	temp+="Table de symboles:\n";
	temp+="id\ttype\ttype2\tvalue\towner\tdeclared\n";
	for (Symbole S : Table) {
		if (S!=null) temp+=S.id+"\t"+S.type+"\t"+S.type2+"\t"+S.val+"\t"+S.owner+"\t\n";								
						}
	temp+="---------------------------------------------------------------";
	return temp;
}

public String getOwnerCourant() {
	return ownerCourant;
}

public void setOwnerCourant(String ownerCourant) {
	this.ownerCourant = ownerCourant;
}
	
	


public String ToHTML()
{	String temp=new String();
	
temp+="<h3><font color=\"green\"><u>Table de symboles:</u></font></b>";
	temp+="<table  bgcolor=\"#99CCFF\" border=\"2\" cellpadding=\"3\" cellspacing=\"2\">";
	temp+="<tr><th>id</th><th>type</th><th>type2</th><th>Value</th><th>owner</th><th>line</th></tr>";
	for (Symbole S : Table) {
		if (S!=null) temp+="<tr><td>"+S.id+"</td><td>"+S.type+"</td><td>"+S.type2+"</td><td>"+S.val+"</td><td>"+S.owner+"</td><td>"+S.line+"</td></tr>";								
						}
	temp+="</table>";
	return temp;
}

public void JoinInHtml(Exception e)
{
	
Log+="<br><font size=\"+1\" color=\"red\">error #<b>"+cptERR+"</b>:</font>"+e.getMessage();	
	
}
public void THROW(String  msg)  throws Exception 
{
	
	throw new Exception(msg);
}

};