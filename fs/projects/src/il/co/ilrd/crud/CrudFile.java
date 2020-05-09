package il.co.ilrd.crud;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.io.Serializable;

public class CrudFile implements GenericCrud<String,Integer> {
	private Integer numberOfLines = 0;
	private BufferedWriter writer;
	
	public CrudFile(String filePath) {
		try {
			writer = new BufferedWriter(new FileWriter(filePath, true));	
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@Override
	public void close() throws Exception {
		writer.close();
	}

	@Override
	public Integer create(String line) {
		try {
			if (line == null) {
				writer.close();
			}
			writer.append(line);
			writer.flush();
			writer.newLine();
			++numberOfLines;
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return numberOfLines;
	}

	@Override
	public String read(Integer key) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void update(Integer key, String obj) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public String delete(Integer key) {
		// TODO Auto-generated method stub
		return null;
	}
}