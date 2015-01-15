package pack;

public class Symbole
{
	Symbole()
	{
	id=new String("");	
	type=new String("");
	type2=new String("");
	val=new String("");
	line=0;
	owner=new String("");
	}
	
	
	public String id;
	public String type;
	public String type2;
	public String owner;
	public String val;
	public int line;	
	
	Symbole(String id,String type,String type2,String owner,String val,int line)
	{
	this.id=id;
	this.type=type;	
	this.type2=type2;
	this.line=line;
	this.owner=owner;
	this.val=val;
		
		
	}
}