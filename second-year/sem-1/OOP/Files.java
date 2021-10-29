
//import java.io.File;

class File
{
	private String information= new String();
	private String name= new String();
	
	public File(String information, String name)
	{
		this.information=information;
		this.name= name;
	}
	
	public String getContent()
	{
		return information;
	}
	
	public boolean equals(Object obj)
	{
        if(obj instanceof File)
		{
			return ((File) obj).name.equals(this.name);
		}
        else
            return false;
		
    }
}


class Folder
{
	
	private File[] f =new File[100];
	private int counter=0;
	
	public boolean addFile(File fileToAdd)
	{
		int added=0;
		for(int i=0; i<counter; i++)
		{
			if(f[i].equals(fileToAdd)) added=1;
		}
		if(added==0)
		{
			f[counter]=fileToAdd;
			counter++;
			return true;
		}	
		return false;
	}
	
	/*public void printFile()
	{
		//System.out.println(f[0].getContent()+ " "+f[0].getName());
	}*/
	
	public String getContent()
	{
		String res=" ";
		for(int i=0; i<counter; i++)
		{
			res +=f[i].getContent();
		}
		return res;
	}
	
}
class Main
{
	public static void main(String[] args)
	{
		File file1= new File("jscsdc djwlscs","Lab1.txt");
		File file2= new File("jdlwcdsvc djwlscs","Lab2.txt");
		
		System.out.println(file1.getContent());
		System.out.println(file2.getContent());
		
		Folder folder1= new Folder();
		
		folder1.addFile(file1);
		folder1.addFile(file2);
		
		System.out.println(folder1.getContent());
	}
	
}