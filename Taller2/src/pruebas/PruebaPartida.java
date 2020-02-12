package pruebas;

import logica.valueObjects.VoPartida;

public class PruebaPartida {

	public static void main(String[] args) 
	{
		VoPartida partida = new VoPartida(1,false,0,0,0);
		
		int nroP = partida.getNroPartida();
		boolean fin = partida.isFinalizada(); 
		int cntInten = partida.getCantIntentosRealizados();
		int puntaje = partida.getPuntajeObtenido();
		int nroSecreto = partida.getNroSecreto();
		
		System.out.println(nroP);
		System.out.println(fin);
		System.out.println(cntInten);
		System.out.println(puntaje);
		System.out.println(nroSecreto);

	}

}
