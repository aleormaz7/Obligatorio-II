package pruebas;

import logica.valueObjects.VoJugador;

public class PruebaVoJugador 
{

	public static void main(String[] args) 
	{
		VoJugador voJug = new VoJugador("ale",0,0,0);
		
		String nom = voJug.getNombre();
		int punt = voJug.getCantPartidasFinalizadas(); 
		int cntPartidasFin = voJug.getCantPartidasFinalizadas();
		int cocie = voJug.getCociente();
		
		System.out.println(nom);
		System.out.println(punt);
		System.out.println(cntPartidasFin);
		System.out.println(cocie);
		
	}

}
