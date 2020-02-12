package pruebas;

import logica.valueObjects.VoPartidaEnCurso;

public class PruebaVoPartidaEnCurso 
{

	public static void main(String[] args) 
	{
		VoPartidaEnCurso partida = new VoPartidaEnCurso(1,false,0,0);
		
		int nroP = partida.getNroPartida();
		boolean fin = partida.isFinalizada(); 
		int cntInten = partida.getCantIntentosRealizados();
		int puntaje = partida.getPuntajeObtenido();
		
		System.out.println(nroP);
		System.out.println(fin);
		System.out.println(cntInten);
		System.out.println(puntaje);
		
		
	}

}
