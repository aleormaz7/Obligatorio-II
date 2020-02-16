package pruebas;

import logica.valueObjects.VoPartida;

public class PruebaVoPartida 
{

	public static void main(String[] args)
	{
		VoPartida partida = new VoPartida(1,false,0,0,500);
		
		int nroP = partida.getNroPartida();
		boolean fin = partida.isFinalizada(); 
		int cntInten = partida.getCantIntentosRealizados();
		int puntaje = partida.getPuntajeObtenido();
		int nroSec = partida.getNroSecreto();
		
		System.out.println(nroP);
		System.out.println(fin);
		System.out.println(cntInten);
		System.out.println(puntaje);
		System.out.println(nroSec);
		

	}

}
