package pack;



public class LexTests {
	
	private static int nbBOpen=0;
//	public static int nbBClose=0;
	private static int nbSBOpen=0;
//	public static int nbSBClose=0;
	private static int nbBegin=0;
	//public static int nbEnd=0;
	
	public static String Log=new String("<h3><font color=\"green\"><u>Analyse Lexical</u></font></b>");
	public static int cptERR=0; 
	
	public static String HighLight=new String("<hr><h3><font color=\"green\"><u>Code on HighLight</u></font></h3><tr><td><font color=\"Maroon\"><b>0</b></font></td><td>");
	
	public static int nbLine=1;
	
	
	private static String[] Pile=new  String[100];
	private static int indexP=0;
	
	private static  String mirage(String element)
	{String Temp=new String("");

	if (element.compareTo("BEGIN")==0) Temp="END";
	if (element.compareTo("(")==0)  Temp=")";
	if (element.compareTo("[")==0)  Temp="]";
	
	if (element.compareTo("END")==0) Temp="BEGIN";
	if (element.compareTo(")")==0)  Temp="(";
	if (element.compareTo("]")==0)  Temp="[";
		
		return Temp;
	}
	
	public static void Empiler(String element)
	{ // element=element.toUpperCase();//
	
		if (element.compareTo("BEGIN")==0) nbBegin++;
		if (element.compareTo("(")==0) nbBOpen++;
		if (element.compareTo("[")==0) nbSBOpen++;
		
			
		Pile[indexP++]=element;
				
		
	}
	
	
	public static boolean Depiler(String element) 
	{  boolean Ok=true;
		int nb=0;
		String Temp;
		
		if (element.compareTo("BEGIN")==0) nb=nbBegin--;
		if (element.compareTo("(")==0) nb=nbBOpen--;
		if (element.compareTo("[")==0) nb=nbSBOpen--;
		
		
		if(nb>0) {	indexP--;
					Temp=Pile[indexP];
				  int cpt=0; 	
				  while (indexP>=0 && Temp.compareTo(element)!=0)
				  {cpt++;
					 Log+="<br><font size=\"+1\" color=\"red\">error#"+(++cptERR)+":</font><b></b>Exepted <font color=\"magenta\"><b>"+mirage(Temp)+"</b></font> 	a la ligne <b>"+nbLine+"</b>";
					 indexP--;
					 Temp=Pile[indexP];
				  }
				  if (indexP<0) { 
				  					Log+="<br><font size=\"+1\" color=\"black\">Error in Lexical analyser#</font><b>:Internal-Error:</b> nombre de "+element+"="+nb+" n'est pas vrie";
				  					Ok=false;
				  					}
				  
		}
		else {
			Log+="<br><font size=\"+1\" color=\"red\">error #"+(++cptERR)+"</font>:un debordement de <font color=\"magenta\"><b>"+mirage(element)+"</b></font> a la ligne <b>"+nbLine+"</b>";
			Ok=false;
				}
	
			
		
	
		
	return Ok;	
		
	}
	
	public static void FinalTest()
	{
		if (nbBOpen>0) {Log+="<br><font size=\"+1\" color=\"red\">error #"+(++cptERR)+"</font>:un debordement par "+nbBOpen +" elements de <font color=\"magenta\"><b>&lt;(&gt;</b></font> ";};
		if (nbSBOpen>0) {Log+="<br><font size=\"+1\" color=\"red\">error #"+(++cptERR)+"</font>:un debordement par "+nbSBOpen +"  elements de <font color=\"magenta\"><b>&lt;[&gt;</b></font> ";};
		if (nbBegin>0) {Log+="<br><font size=\"+1\" color=\"red\">error #"+(++cptERR)+"</font>:un debordement par "+nbBegin +" elements de <font color=\"magenta\"><b>&lt;begin&gt;</b></font> ";};
			
		
	}
	
	public static void declareUnAutorised(String symbole)
	{
		Log+="<br><font size=\"+1\" color=\"red\">error #"+(++cptERR)+"</font>:Unautorised Symbol <font color=\"magenta\"><b> &lt;"+symbole+"&gt; </b></font> ";
	
	}
	
	public static void ReInit()
	{
		
		nbBOpen=0;

		nbSBOpen=0;

		nbBegin=0;
		
		
		Log=new String("<h3><font color=\"green\"><u>Analyse Lexical</u></font></b>");
		cptERR=0; 
		
		Pile=new  String[100];
		indexP=0;
		
		HighLight=new String();
		HighLight="<hr><h3><font color=\"green\"><u>Code on HighLight</u></font></h3>";
		HighLight+="<table  border=\"0\" cellpadding=\"3\" cellspacing=\"2\">";
		HighLight+="<tr><td><font color=\"Maroon\"><b>1</b></font></td><td>";
		nbLine=1;
	}
	
	


	public static void ToHighLight(String word,String color,String size,String Att)
	{String Last="";
	 String First="";
	        for (char c :Att.toCharArray())
	        {First+="<"+c+">";Last="</"+c+">"+Last;};
	First+="<font color=\""+color+"\" size=\""+size+"\">";
	Last="</font>"+Last;

	HighLight+=First+word+Last;

	}
		
	
	
	
	
	
}
