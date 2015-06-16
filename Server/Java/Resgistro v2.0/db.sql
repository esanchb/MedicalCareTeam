-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 28-05-2015 a las 15:04:37
-- Versión del servidor: 5.5.41-0ubuntu0.14.04.1
-- Versión de PHP: 5.5.9-1ubuntu4.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `bd_proyecto_cuerpo`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `doctors`
--

CREATE TABLE IF NOT EXISTS `doctors` (
  `idMedico` int(11) NOT NULL AUTO_INCREMENT,
  `medicName` varchar(20) NOT NULL,
  `medicLastN` varchar(60) NOT NULL,
  `medicSpeciality` varchar(30) NOT NULL,
  `medicLocation` int(11) NOT NULL,
  `medicPass` varchar(20) NOT NULL,
  `usrNameMedic` varchar(20) NOT NULL,
  PRIMARY KEY (`idMedico`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Volcado de datos para la tabla `doctors`
--

INSERT INTO `doctors` (`idMedico`, `medicName`, `medicLastN`, `medicSpeciality`, `medicLocation`, `medicPass`, `usrNameMedic`) VALUES
(1, 'Ericka', 'Monreal Gutierrez', 'general', 1, 'Otro6ato00x', 'erickaMon'),
(2, 'Ramon', 'Gonzales Ramirez', 'general', 1, '123456', 'ramonGon');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `locations`
--

CREATE TABLE IF NOT EXISTS `locations` (
  `idLocation` int(11) NOT NULL AUTO_INCREMENT,
  `nameLocation` varchar(50) NOT NULL,
  `addrssLocation` varchar(50) NOT NULL,
  `stateLocation` varchar(50) NOT NULL,
  `cityLocation` varchar(50) NOT NULL,
  PRIMARY KEY (`idLocation`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Volcado de datos para la tabla `locations`
--

INSERT INTO `locations` (`idLocation`, `nameLocation`, `addrssLocation`, `stateLocation`, `cityLocation`) VALUES
(1, 'Hospital Central', 'Av. Venustiano Carranza', 'San Luis Potosi', 'San Luis Potosi');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `metrics`
--

CREATE TABLE IF NOT EXISTS `metrics` (
  `idMetric` int(11) NOT NULL AUTO_INCREMENT,
  `idPatient` int(11) NOT NULL,
  `idDoctor` int(11) NOT NULL,
  `oxigenMetric` int(11) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`idMetric`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Volcado de datos para la tabla `metrics`
--

INSERT INTO `metrics` (`idMetric`, `idPatient`, `idDoctor`, `oxigenMetric`, `time`) VALUES
(1, 1, 1, 80, '2015-05-25 17:26:30'),
(2, 2, 1, 80, '2015-05-25 17:26:30'),
(3, 1, 1, 75, '2015-05-25 17:27:54'),
(4, 2, 1, 83, '2015-05-25 17:27:59');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `patients`
--

CREATE TABLE IF NOT EXISTS `patients` (
  `idPatient` int(11) NOT NULL AUTO_INCREMENT,
  `patientName` varchar(20) NOT NULL,
  `patientLastN` varchar(60) NOT NULL,
  `patientAge` int(11) NOT NULL,
  `patientSex` int(11) NOT NULL,
  `idDoctor` int(11) NOT NULL,
  PRIMARY KEY (`idPatient`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Volcado de datos para la tabla `patients`
--

INSERT INTO `patients` (`idPatient`, `patientName`, `patientLastN`, `patientAge`, `patientSex`, `idDoctor`) VALUES
(1, 'ramiro', 'agundis arredondo', 22, 1, 1),
(2, 'josue', 'agundis arredondo', 16, 1, 2),
(3, 'ramiro', 'Sanchez Gomez', 27, 1, 2);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
