SamacSys ECAD Model
620310/930445/2.50/3/2/Connector

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "c150_h100"
		(holeDiam 1)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 1.5) (shapeHeight 1.5))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 1.5) (shapeHeight 1.5))
	)
	(padStyleDef "s150_h100"
		(holeDiam 1)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.5) (shapeHeight 1.5))
		(padShape (layerNumRef 16) (padShapeType Rect)  (shapeWidth 1.5) (shapeHeight 1.5))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "SHDR3W78P0X254_1X3_772X252X850" (originalName "SHDR3W78P0X254_1X3_772X252X850")
		(multiLayer
			(pad (padNum 1) (padStyleRef s150_h100) (pt 0, 0) (rotation 90))
			(pad (padNum 2) (padStyleRef c150_h100) (pt 2.54, 0) (rotation 90))
			(pad (padNum 3) (padStyleRef c150_h100) (pt 5.08, 0) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -1.52 -1.51) (pt -1.52 1.51) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -1.52 1.51) (pt 6.9 1.51) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 6.9 1.51) (pt 6.9 -1.51) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 6.9 -1.51) (pt -1.52 -1.51) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.27 -1.26) (pt -1.27 1.26) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.27 1.26) (pt 6.65 1.26) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 6.65 1.26) (pt 6.65 -1.26) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 6.65 -1.26) (pt -1.27 -1.26) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0 -1.26) (pt 6.65 -1.26) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 6.65 -1.26) (pt 6.65 1.26) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 6.65 1.26) (pt -1.27 1.26) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.27 1.26) (pt -1.27 0) (width 0.2))
		)
	)
	(symbolDef "215299-3" (originalName "215299-3")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 600 mils 100 mils) (width 6 mils))
		(line (pt 600 mils 100 mils) (pt 600 mils -300 mils) (width 6 mils))
		(line (pt 600 mils -300 mils) (pt 200 mils -300 mils) (width 6 mils))
		(line (pt 200 mils -300 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 650 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "215299-3" (originalName "215299-3") (compHeader (numPins 3) (numParts 1) (refDesPrefix J)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "3") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "215299-3"))
		(attachedPattern (patternNum 1) (patternName "SHDR3W78P0X254_1X3_772X252X850")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Mouser Part Number" "571-215299-3")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/215299-3?qs=pol9tQvH%252BaHR%252B8PZSmhoEA%3D%3D")
		(attr "Manufacturer_Name" "TE Connectivity")
		(attr "Manufacturer_Part_Number" "215299-3")
		(attr "Description" "Body Features: Primary Product Color Black | Connector Profile Standard | Configuration Features: Number of Rows 1 | Number of Positions 3 | PCB Mount Orientation Vertical | Stackable Yes | Contact Features: Contact Shape & Form Square | Mating Pin Diameter .024 INCH | PCB Contact Termination Area Plating Material Thickness 94.488  157.48 MICIN | Contact Mating Area Plating Material Gold | Mating Pin Diameter .63 MM | Mating Square Post Dimension .63 MM | Contact Base Material Phosphor Bronze | PCB Conta")
		(attr "Datasheet Link" "https://componentsearchengine.com/Datasheets/1/215299-3.pdf")
		(attr "Height" "8.5 mm")
	)

)
