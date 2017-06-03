-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: biblioteca
-- ------------------------------------------------------
-- Server version	5.7.18-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `libro`
--

DROP TABLE IF EXISTS `libro`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `libro` (
  `id` int(11) NOT NULL,
  `nombre` varchar(75) NOT NULL,
  `autor` varchar(75) NOT NULL,
  `fecha` int(11) NOT NULL,
  `categoria` varchar(75) NOT NULL,
  `estanteria` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `libro`
--

LOCK TABLES `libro` WRITE;
/*!40000 ALTER TABLE `libro` DISABLE KEYS */;
INSERT INTO `libro` VALUES (1,'Calculo','James Stewart',2010,'Matematicas',2),(2,'MySQL Tutorial','Varios',2010,'Base de datos',1),(3,'Kotlin','Antonio Leiva',2016,'Programacion',15),(4,'Chess Strategy','Anders Thulin',2007,'Ajedréz',2),(5,'238 Respuestas de física','Varios',2016,'Física',3),(6,'Dangerous Ideas ','Susan Magarey',2014,'Educación',5),(7,'Introducción a la programación con C#','Nacho Cabanes',2012,'Programacion',10),(8,'Evaluador de Expresiones Algebraicas II','Rafael Alberto Moreno Parra',2013,'Programacion',10),(9,'Introducción a .NET','Jordi Ceballos Villach',2009,'Programacion',15),(10,'Métodos Estadísticos para Economía y Empresa','Ana Jesus Lopez Menendez',2011,'Matematicas',1),(11,'Operadores de LINQ','Jesus Rodriguez Rodriguez',2010,'Programacion',1),(12,'El azar y la probabilidad','Varios',2012,'Ciencia',5),(13,'CSS3 y Javascript avanzado','Jordi Collell Puig',2013,'Desarrollo Web',12),(14,'Guía Completa de CSS3','Antonio Navajas Ojeda',2012,'Desarrollo Web',6),(15,'Problemas Resueltos de Algebra','Fernando Revilla Jimenez',2009,'Matematicas',6),(16,'El Psicoanalista','John Katzenbach',0,'Novela',6),(17,'Fundamentos basicos de probramacion c++','Francisco Martinez del Rio',2015,'Programacion',6),(18,'Que es el capitalismo?','Rolando Astarita',2013,'Economia Politica',18),(19,'Resistencia de Materiales','Andrew Pytel, Ferdinand L. Singer',2008,'Ciencia',16),(20,'Álgebra y Trigonometría con Geometría Analítica','Earl W. Swokowski, Jefrey A. Cole',2011,'Matematicas',5),(21,'Precalculo (Matematicas Para El Cálculo)','James Stewart',2012,'Matematicas',2),(100,'Desarrollo de Aplicaciones Web','Carles Mateu',2004,'Desarrollo Web',5);
/*!40000 ALTER TABLE `libro` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-06-03  2:46:31
