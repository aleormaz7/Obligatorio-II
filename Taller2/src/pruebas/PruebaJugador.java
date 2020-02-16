package pruebas;
import logica.jugador.Jugador;

public class PruebaJugador 
{
	public static void main(String[] args) 
	{
		Jugador jug = new Jugador("ale","123");
		String nom = jug.getNombre();
		String cod = jug.getCodigoIngreso();
		
		System.out.println(nom);
		System.out.println(cod);

	}

}
