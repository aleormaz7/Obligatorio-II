package pruebas;

import logica.valueObjects.VoJugadorGeneral;

public class PruebaVoJugadorGeneral 
{

	public static void main(String[] args)
	{
		VoJugadorGeneral voJug = new VoJugadorGeneral("ale",0,0,0,"123");
		
		String nom = voJug.getNombre();
		int punt = voJug.getCantPartidasFinalizadas(); 
		int cntPartidasFin = voJug.getCantPartidasFinalizadas();
		int cocie = voJug.getCociente();
		String codIng = voJug.getCodigoIngreso();
		
		System.out.println(nom);
		System.out.println(punt);
		System.out.println(cntPartidasFin);
		System.out.println(cocie);
		System.out.println(codIng);

	}

}
