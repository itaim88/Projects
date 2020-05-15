package il.co.ilrd.networkingWS;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

public class Download {  
    public static void DownloadWebPage(String webpage) { 
		try { 
			// Create URL object 
		    URL url = new URL(webpage); 
		    BufferedReader readr = new BufferedReader(new InputStreamReader(url.openStream())); 
		  
		    // Enter filename in which you want to download 
		    BufferedWriter writer =  
		    new BufferedWriter(new FileWriter("C:\\Users\\yuval tsuk\\Desktop\\Download.html")); 
		      
		    // read each line from stream till end 
            String line; 
            while ((line = readr.readLine()) != null) { 
            		writer.write(line); 
            } 
  
            readr.close(); 
            writer.close(); 
            System.out.println("Successfully Downloaded."); 
		} 
  
        catch (MalformedURLException mue) { 
            System.out.println("Malformed URL Exception raised"); 
        } 
        catch (IOException ie) { 
            System.out.println("IOException raised"); 
        } 
    } 
    
    public static void main(String args[]) throws IOException { 
    	/*** create web shortcut on desktop ***/
        String url = "https://www.ynet.co.il/home/0,7340,L-8,00.html"; 
        DownloadWebPage(url); 
        
        /*** print to the console ***/
        URL url1;
        InputStream is = null;
        BufferedReader br;
        String line;

        try {
            url1 = new URL("https://www.sport5.co.il/articles.aspx?FolderID=398&docID=341011");
            is = url1.openStream();  // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (MalformedURLException mue) {
             mue.printStackTrace();
        } catch (IOException ioe) {
             ioe.printStackTrace();
        } finally {
            try {
                if (is != null) is.close();
            } catch (IOException ioe) {
                // nothing to see here
            }
        }
    } 
}
