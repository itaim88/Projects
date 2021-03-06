package il.co.ilrd.MultiThreadCountingSort;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Stream;
 
public class TextToString {
	
    public static void main(String[] args) {
        String filePath = "d:/words.txt";
 
        System.out.println(readLineByLineJava8( filePath ) );
    }
 
	static String randomString(String string) {
		
		String[] scram = string.split("");
        List<String> letters = Arrays.asList(scram);
        Collections.shuffle(letters);
        StringBuilder sb = new StringBuilder(string.length());
        for (String c : letters) {
            sb.append(c);
        }
        return sb.toString();
		
	}
    public static String readLineByLineJava8(String filePath) 
    {
        StringBuilder contentBuilder = new StringBuilder();
 
        try (Stream<String> stream = Files.lines( Paths.get(filePath), StandardCharsets.UTF_8)) 
        {
            stream.forEach(s -> contentBuilder.append(s).append("\n"));
        }
        catch (IOException e) 
        {
            e.printStackTrace();
        }
 
        return randomString(contentBuilder.toString());
    }
}

