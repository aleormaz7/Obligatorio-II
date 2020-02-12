package pruebas;

import logica.valueObjects.VoRanking;

public class PruebaVoRanking
{

	public static void main(String[] args) 
	{
		VoRanking rank = new VoRanking("ale",0,0,0,1);
		
		String nom = rank.getNombre();
		int punt = rank.getPuntaje(); 
		int cntPartidsaFin = rank.getCantPartidasFinalizadas();
		int cocie = rank.getCociente();
		int pos = rank.getPosicion();
		
		System.out.println(nom);
		System.out.println(punt);
		System.out.println(cntPartidsaFin);
		System.out.println(cocie);
		System.out.println(pos);

	}

}
