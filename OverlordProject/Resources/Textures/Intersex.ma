//Maya ASCII 2023 scene
//Name: Intersex.ma
//Last modified: Fri, Apr 28, 2023 06:00:34 PM
//Codeset: 1252
requires maya "2023";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" -nodeType "aiStandardSurface"
		 "mtoa" "5.2.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2023";
fileInfo "version" "2023";
fileInfo "cutIdentifier" "202208031415-1dee56799d";
fileInfo "osv" "Windows 10 Education v2009 (Build: 19045)";
fileInfo "UUID" "EC2BC881-4B96-CBA8-88DF-5796E18A455C";
createNode transform -s -n "persp";
	rename -uid "FCE11579-4B02-B25B-6527-30B4CB60C205";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 58.872733899261348 30.404202811231077 -5.8089664574017208 ;
	setAttr ".r" -type "double3" -27.338352729585278 -262.19999999996878 -2.5444437451708134e-14 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "87DA7C23-4700-3CCD-1942-1AA5F346145F";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 62.340868881032392;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" 6.6889760219623895e-07 0 -12.017766952514666 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
createNode transform -s -n "top";
	rename -uid "104C2534-479F-8A09-2ADE-9689D194BD50";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 1000.1 0 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "7662AF07-4546-D49E-1581-A9A7F1C2A35C";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "F384D26C-4646-B5FC-2095-6AA0862272AE";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "9EDAC63B-4AD5-BDFA-D705-8CBD41F744E6";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "1969462E-496D-C406-E7AE-DB83486F4763";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 0 0 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "D030026F-4DED-C5D4-1C80-1FA0EFE4798F";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "Model_0";
	rename -uid "ED205EA3-4900-F82D-D3FF-E89FEE326AE8";
	setAttr ".r" -type "double3" -90 89.999995674288911 0 ;
	setAttr ".s" -type "double3" 1.0000000000000029 1.0000000000000029 1 ;
createNode mesh -n "Model_0Shape" -p "Model_0";
	rename -uid "149AB01E-461E-5937-45ED-8F8F7948AE00";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.3768409515207245 0.50479839204436172 ;
	setAttr ".uvst[0].uvsn" -type "string" "UVMap";
	setAttr ".cuvs" -type "string" "UVMap";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 5 ".pt";
	setAttr ".pt[32]" -type "float3" 0 5.6843419e-14 0 ;
createNode mesh -n "polySurfaceShape1" -p "Model_0";
	rename -uid "67088FBA-4D7A-8483-8404-82B0ED22F1F1";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "UVMap";
	setAttr -s 20 ".uvst[0].uvsp[0:19]" -type "float2" 0 1 1 0.25 1 1 0.99297798
		 0.022438001 0 0.25 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001
		 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001
		 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001
		 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001;
	setAttr ".cuvs" -type "string" "UVMap";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 20 ".vt[0:19]"  12 -12.000001907349 -1 8 -12 -1 8 12.000001907349 -1
		 12 12 -1 12 -12.000001907349 0.40000001 8 -12 0.40000001 8 12.000001907349 0.40000001
		 12 12 0.40000001 -8 -12.000001907349 -1 -12 -12 -1 -12 12.000001907349 -1 -8 12 -1
		 -8 -12.000001907349 0.40000001 -12 -12 0.40000001 -12 12.000001907349 0.40000001
		 -8 12 0.40000001 8 -12.000001907349 0 8.000000953674 12 0 -8.000000953674 -12 0 -8 12.000001907349 0;
	setAttr -s 24 ".ed[0:23]"  5 6 0 6 2 0 2 1 0 1 5 0 7 4 0 4 0 0 0 3 0
		 3 7 0 7 6 0 5 4 0 13 14 0 14 10 0 10 9 0 9 13 0 15 12 0 12 8 0 8 11 0 11 15 0 15 14 0
		 13 12 0 16 17 0 17 19 0 19 18 0 18 16 0;
	setAttr -s 28 ".n[0:27]" -type "float3"  -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 1 0 0 1 0 0 1 0 0 1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 1 0 0
		 1 0 0 1 0 0 1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1;
	setAttr -s 7 -ch 28 ".fc[0:6]" -type "polyFaces" 
		f 4 0 1 2 3
		mu 0 4 3 5 6 7
		f 4 4 5 6 7
		mu 0 4 8 9 10 11
		f 4 8 -1 9 -5
		mu 0 4 8 5 3 9
		f 4 10 11 12 13
		mu 0 4 12 13 14 15
		f 4 14 15 16 17
		mu 0 4 16 17 18 19
		f 4 18 -11 19 -15
		mu 0 4 16 13 12 17
		f 4 20 21 22 23
		mu 0 4 0 4 1 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "group";
	rename -uid "E86538CB-4153-0EFF-295A-F6BDBC3053B3";
	setAttr ".rp" -type "double3" 0 -0.29999999701976776 0 ;
	setAttr ".sp" -type "double3" 0 -0.29999999701976776 0 ;
createNode transform -n "pasted__Model_0" -p "group";
	rename -uid "851DD53D-4B7C-260C-BABF-BDA535F15C4E";
	setAttr ".r" -type "double3" -90.000000000000043 0 0 ;
	setAttr ".s" -type "double3" 1.0000000000000029 1.0000000000000029 1 ;
createNode mesh -n "pasted__Model_0Shape" -p "pasted__Model_0";
	rename -uid "00F54928-4F33-7F3B-5EE0-D9AA9451A7E6";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.25 ;
	setAttr ".uvst[0].uvsn" -type "string" "UVMap";
	setAttr -s 20 ".uvst[0].uvsp[0:19]" -type "float2" 0 1 1 0.25 1 1 0.99297798
		 0.022438001 0 0.25 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001
		 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001
		 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001
		 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001 0.99297798 0.022438001;
	setAttr ".cuvs" -type "string" "UVMap";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 20 ".vt[0:19]"  12 -12.000001907349 -1 8 -12 -1 8 12.000001907349 -1
		 12 12 -1 12 -12.000001907349 0.40000001 8 -12 0.40000001 8 12.000001907349 0.40000001
		 12 12 0.40000001 -8 -12.000001907349 -1 -12 -12 -1 -12 12.000001907349 -1 -8 12 -1
		 -8 -12.000001907349 0.40000001 -12 -12 0.40000001 -12 12.000001907349 0.40000001
		 -8 12 0.40000001 8 -12.000001907349 0 8.000000953674 12 0 -8.000000953674 -12 0 -8 12.000001907349 0;
	setAttr -s 24 ".ed[0:23]"  5 6 0 6 2 0 2 1 0 1 5 0 7 4 0 4 0 0 0 3 0
		 3 7 0 7 6 0 5 4 0 13 14 0 14 10 0 10 9 0 9 13 0 15 12 0 12 8 0 8 11 0 11 15 0 15 14 0
		 13 12 0 16 17 0 17 19 0 19 18 0 18 16 0;
	setAttr -s 28 ".n[0:27]" -type "float3"  -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 1 0 0 1 0 0 1 0 0 1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 1 0 0
		 1 0 0 1 0 0 1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1;
	setAttr -s 7 -ch 28 ".fc[0:6]" -type "polyFaces" 
		f 4 0 1 2 3
		mu 0 4 3 5 6 7
		f 4 4 5 6 7
		mu 0 4 8 9 10 11
		f 4 8 -1 9 -5
		mu 0 4 8 5 3 9
		f 4 10 11 12 13
		mu 0 4 12 13 14 15
		f 4 14 15 16 17
		mu 0 4 16 17 18 19
		f 4 18 -11 19 -15
		mu 0 4 16 13 12 17
		f 4 20 21 22 23
		mu 0 4 0 4 1 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode lightLinker -s -n "lightLinker1";
	rename -uid "1EFD22F5-4ED5-19E4-5CB0-09A5E108CCA9";
	setAttr -s 6 ".lnk";
	setAttr -s 6 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "A1CA7ACE-4EC3-6811-C781-3DB3C8BBCB85";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "C9F04321-4FF5-1FF2-285A-FAB1C861303C";
createNode displayLayerManager -n "layerManager";
	rename -uid "73570B10-4A0F-0F64-A4CA-66AB184F9E8F";
createNode displayLayer -n "defaultLayer";
	rename -uid "926519FF-4C5A-1843-363C-A88B0298CD88";
	setAttr ".ufem" -type "stringArray" 0  ;
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "F2E69F91-48E1-6915-1FB8-97B17FF34047";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "07E05F6A-4508-AE85-EED0-B8A9C70D7DA2";
	setAttr ".g" yes;
createNode aiOptions -s -n "defaultArnoldRenderOptions";
	rename -uid "2D7702E2-422F-BF41-0841-B999CBD1282D";
	setAttr ".version" -type "string" "5.2.0";
createNode aiAOVFilter -s -n "defaultArnoldFilter";
	rename -uid "792942E9-47FF-3B55-76C2-B18819CEA138";
	setAttr ".ai_translator" -type "string" "gaussian";
createNode aiAOVDriver -s -n "defaultArnoldDriver";
	rename -uid "BF9C8A88-4BC4-B450-8677-449718C81AC0";
	setAttr ".ai_translator" -type "string" "exr";
createNode aiAOVDriver -s -n "defaultArnoldDisplayDriver";
	rename -uid "98CC9025-420A-863B-FD0C-679C846FCC6D";
	setAttr ".output_mode" 0;
	setAttr ".ai_translator" -type "string" "maya";
createNode phong -n "None__Texture_png";
	rename -uid "9C131EE9-4BE0-A82C-C5A8-DBB52A4D7728";
	setAttr ".ambc" -type "float3" 1 1 1 ;
	setAttr ".rfl" 1;
	setAttr ".cp" 12.300000190734863;
createNode shadingEngine -n "Model_0SG";
	rename -uid "3FE6F619-4060-3D72-4249-94AB29AB0C92";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo1";
	rename -uid "7A13A2D6-492B-3A62-418A-559A4BAC08E1";
createNode file -n "Texture_png";
	rename -uid "3848A728-4ED3-7B6C-BC3C-63A8523F3076";
	setAttr ".ftn" -type "string" "Texture.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture1";
	rename -uid "922B63B7-41DE-D387-98FD-848C3A0C4238";
createNode materialInfo -n "pasted__materialInfo1";
	rename -uid "72E5976D-46E9-7A49-F5D9-489261ABFF6F";
createNode shadingEngine -n "pasted__Model_0SG";
	rename -uid "FE2A576C-4741-BA2F-3442-EC8D5DC76276";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode phong -n "pasted__None__Texture_png";
	rename -uid "068DE3B0-45CE-69D2-FA6D-1292AC0E52D4";
	setAttr ".ambc" -type "float3" 1 1 1 ;
	setAttr ".rfl" 1;
	setAttr ".cp" 12.300000190734863;
createNode file -n "pasted__Texture_png";
	rename -uid "66B21248-420A-0505-C97F-52B633059D6D";
	setAttr ".ftn" -type "string" "Texture.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "pasted__place2dTexture1";
	rename -uid "9CE52BED-4233-443B-AC73-1899C55D1083";
createNode materialInfo -n "pasted__materialInfo2";
	rename -uid "AF0C0142-476D-F73C-FB42-D294EA8C09AC";
createNode shadingEngine -n "pasted__Model_0SG1";
	rename -uid "1A5B0047-42C2-38E5-ABA3-DD9C8DFA0FC5";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode phong -n "pasted__None__Texture_png1";
	rename -uid "0B8547D0-4978-9CD7-6A3B-9E83C63782BA";
	setAttr ".ambc" -type "float3" 1 1 1 ;
	setAttr ".rfl" 1;
	setAttr ".cp" 12.300000190734863;
createNode file -n "pasted__Texture_png1";
	rename -uid "B6551A28-4136-A192-5A3C-0FB21398FB88";
	setAttr ".ftn" -type "string" "Texture.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "pasted__place2dTexture2";
	rename -uid "AEC99685-4DDA-4C92-4D69-208EB69182E4";
createNode polySplit -n "polySplit1";
	rename -uid "0CD454A2-4745-422C-49CA-8DB90381AC0D";
	setAttr -s 4 ".e[0:3]"  0.2 0.80000001 0.2 0.80000001;
	setAttr -s 4 ".d[0:3]"  -2147483642 -2147483644 -2147483648 -2147483646;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "polySplit2";
	rename -uid "2A7950A4-49A3-8DD5-9C9C-399AEF2D63E3";
	setAttr -s 4 ".e[0:3]"  0.2 0.80000001 0.2 0.80000001;
	setAttr -s 4 ".d[0:3]"  -2147483632 -2147483634 -2147483638 -2147483636;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "polySplit3";
	rename -uid "D0AFB78C-4BE1-0100-7063-FAAD57C4A7A0";
	setAttr -s 4 ".e[0:3]"  0.2 0.80000001 0.2 0.80000001;
	setAttr -s 4 ".d[0:3]"  -2147483646 -2147483622 -2147483644 -2147483624;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "polySplit4";
	rename -uid "D602A4EF-4D98-94E2-7EF1-35B39B81C2F3";
	setAttr -s 4 ".e[0:3]"  0.2 0.80000001 0.2 0.80000001;
	setAttr -s 4 ".d[0:3]"  -2147483636 -2147483615 -2147483634 -2147483617;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "polySplit5";
	rename -uid "5D4ACA93-480E-6526-181A-2E83ABCFFA9D";
	setAttr -s 2 ".e[0:1]"  0.2 0.80000001;
	setAttr -s 2 ".d[0:1]"  -2147483628 -2147483626;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polySplit -n "polySplit6";
	rename -uid "556A700A-41CB-660D-B838-DEA3D235649D";
	setAttr -s 2 ".e[0:1]"  0.2 0.80000001;
	setAttr -s 2 ".d[0:1]"  -2147483626 -2147483596;
	setAttr ".sma" 180;
	setAttr ".m2015" yes;
createNode polyExtrudeFace -n "polyExtrudeFace1";
	rename -uid "9E038DAC-46B5-F14E-A5DF-F29D5878AFC3";
	setAttr ".ics" -type "componentList" 2 "f[14]" "f[17]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 0 0.40000004 0 ;
	setAttr ".rs" 60255;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -8.0000018596491298 0.40000003576278687 -12.000000603983137 ;
	setAttr ".cbx" -type "double3" 8.0000018596491298 0.40000003576278687 12.000000603983137 ;
	setAttr ".raf" no;
createNode polyTweak -n "polyTweak1";
	rename -uid "C1D3ACF6-49E2-CC0F-EF4A-E990F7238B7B";
	setAttr ".uopa" yes;
	setAttr -s 20 ".tk[20:39]" -type "float3"  6.0398264e-08 -0.79999924
		 0 6.0398264e-08 -0.79999924 0 6.0398264e-08 -0.79999924 0 6.0398264e-08 -0.79999924
		 0 6.0398264e-08 -0.79999924 0 6.0398264e-08 -0.79999924 0 6.0398264e-08 -0.79999924
		 0 6.0398264e-08 -0.79999924 0 1.2079724e-08 -0.1600008 0 1.2079724e-08 -0.1600008
		 0 1.2079724e-08 -0.1600008 0 1.2079724e-08 -0.1600008 0 1.2079724e-08 -0.1600008
		 0 1.2079724e-08 -0.1600008 0 1.2079725e-08 -0.1600008 0 1.2079725e-08 -0.1600008
		 0 6.0398264e-08 -0.79999924 0 6.0398264e-08 -0.79999924 0 1.2079725e-08 -0.1600008
		 0 1.2079724e-08 -0.1600008 0;
createNode polyTweak -n "polyTweak2";
	rename -uid "E426A7DA-42BD-1DF7-EA94-18AF77D383C2";
	setAttr ".uopa" yes;
	setAttr -s 11 ".tk";
	setAttr ".tk[40]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[41]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[42]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[43]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[44]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[45]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[46]" -type "float3" 0 0 -0.39503181 ;
	setAttr ".tk[47]" -type "float3" 0 0 -0.39503181 ;
createNode deleteComponent -n "deleteComponent1";
	rename -uid "16280ACD-4CDA-D822-246B-468793F156D1";
	setAttr ".dc" -type "componentList" 1 "f[18]";
createNode deleteComponent -n "deleteComponent2";
	rename -uid "364CA5E4-4324-0BD8-5B43-E4B25E86F8A8";
	setAttr ".dc" -type "componentList" 1 "f[16]";
createNode deleteComponent -n "deleteComponent3";
	rename -uid "9AD70852-4CF5-AB90-43B4-D0A6FBFB2CA7";
	setAttr ".dc" -type "componentList" 1 "f[24]";
createNode deleteComponent -n "deleteComponent4";
	rename -uid "406B0FD8-4101-3126-40C9-3F8263E1A309";
	setAttr ".dc" -type "componentList" 1 "f[25]";
createNode deleteComponent -n "deleteComponent5";
	rename -uid "30D7CDE4-43E1-B4ED-EBBF-E08DC340DE5E";
	setAttr ".dc" -type "componentList" 1 "f[13]";
createNode deleteComponent -n "deleteComponent6";
	rename -uid "C52430DB-42EE-9D1E-F396-BD81BC7FFC39";
	setAttr ".dc" -type "componentList" 1 "f[19]";
createNode deleteComponent -n "deleteComponent7";
	rename -uid "B6561DB7-4066-FB99-EBC5-C8912D057044";
	setAttr ".dc" -type "componentList" 1 "f[14]";
createNode deleteComponent -n "deleteComponent8";
	rename -uid "76EEC9C5-4224-1034-9990-2997B6A08316";
	setAttr ".dc" -type "componentList" 1 "f[19]";
createNode deleteComponent -n "deleteComponent9";
	rename -uid "69F67BD5-4080-BD56-389D-ACA7310CBF40";
	setAttr ".dc" -type "componentList" 1 "f[1]";
createNode deleteComponent -n "deleteComponent10";
	rename -uid "B1BA8562-4A8E-77A4-432B-6583C0EE041B";
	setAttr ".dc" -type "componentList" 1 "f[11]";
createNode deleteComponent -n "deleteComponent11";
	rename -uid "1AE7C31E-4855-F732-6FD5-429E12F69C3E";
	setAttr ".dc" -type "componentList" 1 "f[2]";
createNode deleteComponent -n "deleteComponent12";
	rename -uid "6AF6FCDE-4464-79D2-221D-3D9DDE122128";
	setAttr ".dc" -type "componentList" 1 "f[5]";
createNode groupId -n "groupId1";
	rename -uid "25A6FA20-471B-3AE8-5E78-A884932DBEC3";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts1";
	rename -uid "32BB1705-4DD7-F078-67B7-37B407EFDE4A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[19:20]";
createNode aiStandardSurface -n "aiStandardSurface1";
	rename -uid "378E9EF0-4E07-9370-F9FA-D6B0BC07F540";
createNode shadingEngine -n "aiStandardSurface1SG";
	rename -uid "83060C84-40C6-814E-06A6-0794BE055EFC";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo2";
	rename -uid "459A9D1F-40C6-C981-87A7-2CB6C5682B1A";
createNode file -n "file1";
	rename -uid "CEFAA8AC-4BE6-FD44-6F65-B0BD188F4E5A";
	setAttr ".ftn" -type "string" "D:/Graphics programming 2/GP2-Unturned/OverlordProject/Resources/Textures/Road.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture2";
	rename -uid "2728D573-446C-A1CB-D4A1-80855A803823";
createNode polyAutoProj -n "polyAutoProj1";
	rename -uid "C68B5907-4C79-6BAD-0AB2-D1BCFF344F7E";
	setAttr ".cch" yes;
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "f[4]" "f[9:12]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".uvs" -type "string" "UVMap";
	setAttr ".s" -type "double3" 24.000005022663686 24.000005022663686 24.000005022663686 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyTweakUV -n "polyTweakUV1";
	rename -uid "E7BED994-4D36-9DB1-1338-9DABADAA5750";
	setAttr ".uopa" yes;
	setAttr -s 17 ".uvtk";
	setAttr ".uvtk[32]" -type "float2" -0.51472151 0.43744099 ;
	setAttr ".uvtk[33]" -type "float2" -0.51472151 0.29986781 ;
	setAttr ".uvtk[34]" -type "float2" 0.035571046 0.29986778 ;
	setAttr ".uvtk[35]" -type "float2" 0.035571046 0.43744093 ;
	setAttr ".uvtk[36]" -type "float2" -0.51472157 -0.25042477 ;
	setAttr ".uvtk[37]" -type "float2" 0.035571016 -0.25042483 ;
	setAttr ".uvtk[38]" -type "float2" -0.51472157 -0.38799778 ;
	setAttr ".uvtk[39]" -type "float2" 0.035571016 -0.3879979 ;
	setAttr ".uvtk[40]" -type "float2" -0.65900749 -0.11285153 ;
	setAttr ".uvtk[41]" -type "float2" -0.52143443 -0.11285165 ;
	setAttr ".uvtk[42]" -type "float2" -0.52143443 0.43744093 ;
	setAttr ".uvtk[43]" -type "float2" -0.65900749 0.43744099 ;
	setAttr ".uvtk[44]" -type "float2" -0.80292773 -0.11285153 ;
	setAttr ".uvtk[45]" -type "float2" -0.66535455 -0.11285165 ;
	setAttr ".uvtk[46]" -type "float2" -0.66535455 0.43744093 ;
	setAttr ".uvtk[47]" -type "float2" -0.80292773 0.43744099 ;
	setAttr ".uvs" -type "string" "UVMap";
createNode polyAutoProj -n "polyAutoProj2";
	rename -uid "B4F7ADB3-4D2D-0278-9976-E5BE2B57D5F9";
	setAttr ".cch" yes;
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 3 "f[0:3]" "f[5:8]" "f[13:16]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".uvs" -type "string" "UVMap";
	setAttr ".s" -type "double3" 24.000005626646892 24.000005626646892 24.000005626646892 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyTweakUV -n "polyTweakUV2";
	rename -uid "40AD5B9E-46ED-AA72-91AF-89ABA2EC9CBC";
	setAttr ".uopa" yes;
	setAttr -s 49 ".uvtk";
	setAttr ".uvtk[16]" -type "float2" 0.87770039 0.017023925 ;
	setAttr ".uvtk[17]" -type "float2" 0.87770039 -0.30324551 ;
	setAttr ".uvtk[18]" -type "float2" 0.98979461 -0.30324551 ;
	setAttr ".uvtk[19]" -type "float2" 0.98979461 0.017023925 ;
	setAttr ".uvtk[20]" -type "float2" 0.41898456 -0.30324566 ;
	setAttr ".uvtk[21]" -type "float2" 0.53107882 -0.30324557 ;
	setAttr ".uvtk[22]" -type "float2" 0.53107882 0.017023925 ;
	setAttr ".uvtk[23]" -type "float2" 0.41898456 0.017023925 ;
	setAttr ".uvtk[24]" -type "float2" 0.49930573 -0.31623867 ;
	setAttr ".uvtk[25]" -type "float2" 0.38721147 -0.31623867 ;
	setAttr ".uvtk[26]" -type "float2" 0.38721147 -0.63650811 ;
	setAttr ".uvtk[27]" -type "float2" 0.49930573 -0.63650811 ;
	setAttr ".uvtk[28]" -type "float2" 0.62042451 -0.63650811 ;
	setAttr ".uvtk[29]" -type "float2" 0.62042451 -0.31623867 ;
	setAttr ".uvtk[30]" -type "float2" 0.50833029 -0.31623867 ;
	setAttr ".uvtk[31]" -type "float2" 0.50833029 -0.63650811 ;
	setAttr ".uvtk[32]" -type "float2" 0.95932382 -0.6495012 ;
	setAttr ".uvtk[33]" -type "float2" 0.95932382 -0.96977049 ;
	setAttr ".uvtk[34]" -type "float2" 0.99095303 -0.96977049 ;
	setAttr ".uvtk[35]" -type "float2" 0.99095303 -0.6495012 ;
	setAttr ".uvtk[36]" -type "float2" 0.95209759 -0.96977025 ;
	setAttr ".uvtk[37]" -type "float2" 0.95209759 -0.64950109 ;
	setAttr ".uvtk[38]" -type "float2" 0.92046851 -0.64950109 ;
	setAttr ".uvtk[39]" -type "float2" 0.92046851 -0.96977025 ;
	setAttr ".uvtk[40]" -type "float2" 0.88179702 -0.6495012 ;
	setAttr ".uvtk[41]" -type "float2" 0.88179702 -0.96977049 ;
	setAttr ".uvtk[42]" -type "float2" 0.91342622 -0.96977049 ;
	setAttr ".uvtk[43]" -type "float2" 0.91342622 -0.6495012 ;
	setAttr ".uvtk[44]" -type "float2" 0.87475485 -0.96977049 ;
	setAttr ".uvtk[45]" -type "float2" 0.87475485 -0.64950109 ;
	setAttr ".uvtk[46]" -type "float2" 0.84312576 -0.64950109 ;
	setAttr ".uvtk[47]" -type "float2" 0.84312576 -0.96977049 ;
	setAttr ".uvtk[48]" -type "float2" 0.54480553 -0.30324557 ;
	setAttr ".uvtk[49]" -type "float2" 0.86507487 -0.30324572 ;
	setAttr ".uvtk[50]" -type "float2" 0.86507487 0.017023752 ;
	setAttr ".uvtk[51]" -type "float2" 0.54480553 0.017023925 ;
	setAttr ".uvtk[52]" -type "float2" 0.086273775 -0.30324557 ;
	setAttr ".uvtk[53]" -type "float2" 0.40654317 -0.30324572 ;
	setAttr ".uvtk[54]" -type "float2" 0.40654317 0.017023752 ;
	setAttr ".uvtk[55]" -type "float2" 0.086273775 0.017023925 ;
	setAttr ".uvtk[56]" -type "float2" 0.054920509 -0.63650811 ;
	setAttr ".uvtk[57]" -type "float2" 0.37518981 -0.63650835 ;
	setAttr ".uvtk[58]" -type "float2" 0.37518981 -0.31623891 ;
	setAttr ".uvtk[59]" -type "float2" 0.054920509 -0.31623867 ;
	setAttr ".uvtk[60]" -type "float2" 0.63244587 -0.63650811 ;
	setAttr ".uvtk[61]" -type "float2" 0.95271522 -0.63650835 ;
	setAttr ".uvtk[62]" -type "float2" 0.95271522 -0.31623891 ;
	setAttr ".uvtk[63]" -type "float2" 0.63244587 -0.31623867 ;
	setAttr ".uvs" -type "string" "UVMap";
createNode deleteComponent -n "deleteComponent13";
	rename -uid "B0D27DD3-435F-C3D3-364B-F1B26BCC9072";
	setAttr ".dc" -type "componentList" 1 "e[53]";
createNode deleteComponent -n "deleteComponent14";
	rename -uid "7309AEA8-4F81-DE77-7835-DC9ECAE68D51";
	setAttr ".dc" -type "componentList" 1 "e[53]";
createNode deleteComponent -n "deleteComponent15";
	rename -uid "65018B41-469C-1320-B163-03952DD308F4";
	setAttr ".dc" -type "componentList" 1 "e[53]";
createNode deleteComponent -n "deleteComponent16";
	rename -uid "1D5669AA-432E-1473-3A32-E1B32039BF85";
	setAttr ".dc" -type "componentList" 1 "e[35]";
createNode deleteComponent -n "deleteComponent17";
	rename -uid "69E2BEEB-46F5-974C-5FF1-6DAED0E30512";
	setAttr ".dc" -type "componentList" 1 "e[34]";
createNode deleteComponent -n "deleteComponent18";
	rename -uid "E5EF7678-4F28-D639-38E8-1D81A670FEC3";
	setAttr ".dc" -type "componentList" 1 "e[36]";
createNode deleteComponent -n "deleteComponent19";
	rename -uid "87B99469-43EF-C6B3-3E15-8290D11F8AA6";
	setAttr ".dc" -type "componentList" 1 "e[40]";
createNode polyDelEdge -n "polyDelEdge1";
	rename -uid "66764FD2-4796-18E8-8BB3-21A9BDFFE632";
	setAttr ".ics" -type "componentList" 1 "e[40]";
	setAttr ".cv" yes;
createNode polyAutoProj -n "polyAutoProj3";
	rename -uid "25C9155D-4035-9C7E-5C43-67AD946D0507";
	setAttr ".cch" yes;
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[8:10]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".uvs" -type "string" "UVMap";
	setAttr ".s" -type "double3" 24.000005022663686 24.000005022663686 24.000005022663686 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyTweakUV -n "polyTweakUV3";
	rename -uid "F81D2E14-4136-C344-2FE8-4FA4A64574BF";
	setAttr ".uopa" yes;
	setAttr -s 17 ".uvtk";
	setAttr ".uvtk[48]" -type "float2" -0.63648021 -0.11635502 ;
	setAttr ".uvtk[49]" -type "float2" -0.5058471 -0.11635502 ;
	setAttr ".uvtk[50]" -type "float2" -0.5058471 0.40617773 ;
	setAttr ".uvtk[51]" -type "float2" -0.63648021 0.40617779 ;
	setAttr ".uvtk[52]" -type "float2" -0.77314031 -0.11635502 ;
	setAttr ".uvtk[53]" -type "float2" -0.6425072 -0.11635502 ;
	setAttr ".uvtk[54]" -type "float2" -0.6425072 0.40617773 ;
	setAttr ".uvtk[55]" -type "float2" -0.77314031 0.40617779 ;
	setAttr ".uvtk[56]" -type "float2" -0.49947289 -0.24698827 ;
	setAttr ".uvtk[57]" -type "float2" -0.49947289 -0.37762138 ;
	setAttr ".uvtk[58]" -type "float2" 0.023059979 -0.3776215 ;
	setAttr ".uvtk[59]" -type "float2" 0.023059979 -0.24698833 ;
	setAttr ".uvtk[60]" -type "float2" 0.023060009 0.27554452 ;
	setAttr ".uvtk[61]" -type "float2" 0.023060009 0.40617773 ;
	setAttr ".uvtk[62]" -type "float2" -0.49947283 0.40617782 ;
	setAttr ".uvtk[63]" -type "float2" -0.49947283 0.27554455 ;
	setAttr ".uvs" -type "string" "UVMap";
createNode deleteComponent -n "deleteComponent20";
	rename -uid "0A7876C4-4EE0-40F5-55AB-738DBE2CBD12";
	setAttr ".dc" -type "componentList" 1 "f[8]";
createNode deleteComponent -n "deleteComponent21";
	rename -uid "EA02ABFB-4518-5236-5D12-0885DAA04C73";
	setAttr ".dc" -type "componentList" 1 "f[8]";
createNode polyExtrudeEdge -n "polyExtrudeEdge1";
	rename -uid "EB879CC1-41B2-E310-0D14-B5BFFD188435";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[32]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 1.0808204e-06 0 -8 ;
	setAttr ".rs" 60125;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -7.9999984423424024 0 -8.0000015576574537 ;
	setAttr ".cbx" -type "double3" 8.0000006039832101 0 -7.9999993960167899 ;
createNode polyExtrudeEdge -n "polyExtrudeEdge2";
	rename -uid "87CAAA51-46D3-23AF-23B1-AD8AD2959438";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[34]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -1.5576576e-06 0 8 ;
	setAttr ".rs" 59388;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -8.0000015576575265 0 7.9999993960167179 ;
	setAttr ".cbx" -type "double3" 7.9999984423424024 0 8.0000015576574537 ;
createNode polyTweak -n "polyTweak3";
	rename -uid "A8A3011D-4BAD-08D9-D010-D890B4B8DA4C";
	setAttr ".uopa" yes;
	setAttr -s 20 ".tk";
	setAttr ".tk[28]" -type "float3" 0 -1.4210855e-14 0 ;
	setAttr ".tk[31]" -type "float3" 0 -1.4210855e-14 0 ;
	setAttr ".tk[40]" -type "float3" 4.0177665 3.033328e-07 0 ;
	setAttr ".tk[41]" -type "float3" 4.0177665 3.033328e-07 0 ;
createNode polyMergeVert -n "polyMergeVert1";
	rename -uid "8ED1F485-4D8C-8954-9191-F88506325C31";
	setAttr ".ics" -type "componentList" 1 "vtx[0:43]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".am" yes;
createNode polyTweak -n "polyTweak4";
	rename -uid "F8C44D30-4087-8B43-880E-6E9E7BF29034";
	setAttr ".uopa" yes;
	setAttr -s 7 ".tk";
	setAttr ".tk[40]" -type "float3" -0.017766953 -1.3413679e-09 0 ;
	setAttr ".tk[41]" -type "float3" -0.017766953 -1.3413679e-09 0 ;
	setAttr ".tk[42]" -type "float3" -3.9999995 -3.0199161e-07 0 ;
	setAttr ".tk[43]" -type "float3" -3.9999995 -3.0199161e-07 0 ;
createNode polyAutoProj -n "polyAutoProj4";
	rename -uid "A14BBBE5-4D08-E92A-8512-DEB2B633F41E";
	setAttr ".cch" yes;
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "f[8]" "f[13:14]";
	setAttr ".ix" -type "matrix" 7.549790115302123e-08 0 -1 0 -1 0 -7.5497901208532382e-08 0
		 0 1 0 0 0 0 0 1;
	setAttr ".uvs" -type "string" "UVMap";
	setAttr ".s" -type "double3" 24.000005022663686 24.000005022663686 24.000005022663686 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyTweakUV -n "polyTweakUV4";
	rename -uid "D645EFEB-4601-8A91-FDE6-ECB065A0EE55";
	setAttr ".uopa" yes;
	setAttr -s 13 ".uvtk";
	setAttr ".uvtk[48]" -type "float2" -0.40993649 -0.28197905 ;
	setAttr ".uvtk[49]" -type "float2" -0.40993655 -0.4253678 ;
	setAttr ".uvtk[50]" -type "float2" 0.16361862 -0.42536792 ;
	setAttr ".uvtk[51]" -type "float2" 0.16361862 -0.28197905 ;
	setAttr ".uvtk[52]" -type "float2" 0.16361862 0.29157597 ;
	setAttr ".uvtk[53]" -type "float2" 0.16361865 0.43496472 ;
	setAttr ".uvtk[54]" -type "float2" -0.40993649 0.43496478 ;
	setAttr ".uvtk[55]" -type "float2" -0.40993649 0.29157594 ;
	setAttr ".uvtk[56]" -type "float2" 0.30700737 -0.28197911 ;
	setAttr ".uvtk[57]" -type "float2" 0.30700737 0.29157594 ;
	setAttr ".uvtk[58]" -type "float2" -0.55332518 0.29157597 ;
	setAttr ".uvtk[59]" -type "float2" -0.55332518 -0.28197899 ;
	setAttr ".uvs" -type "string" "UVMap";
createNode script -n "uiConfigurationScriptNode";
	rename -uid "E99137A5-4AAC-092C-4BB2-15B95CF9D8BA";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 2\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -bluePencil 1\n            -greasePencils 0\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 2\n            -textureAnisotropic 0\n            -textureHilight 1\n"
		+ "            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n"
		+ "            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -bluePencil 1\n            -greasePencils 0\n            -shadows 0\n            -captureSequenceNumber -1\n"
		+ "            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n"
		+ "            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 2\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n"
		+ "            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n"
		+ "            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -bluePencil 1\n            -greasePencils 0\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n"
		+ "            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 2\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n"
		+ "            -isFiltered 1\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n"
		+ "            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -bluePencil 1\n            -greasePencils 0\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1958\n            -height 1091\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n"
		+ "\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 1\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n"
		+ "            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n"
		+ "            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n"
		+ "            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n"
		+ "            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n"
		+ "                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n"
		+ "                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showPlayRangeShades \"on\" \n                -lockPlayRangeShades \"off\" \n"
		+ "                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -keyMinScale 1\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -valueLinesToggle 1\n                -highlightAffectedCurves 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n"
		+ "                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n"
		+ "                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayValues 0\n"
		+ "                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n"
		+ "            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n"
		+ "                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -connectedGraphingMode 1\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n"
		+ "                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -showUnitConversions 0\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n"
		+ "                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -connectedGraphingMode 1\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -showUnitConversions 0\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 2\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 1\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -bluePencil 1\\n    -greasePencils 0\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1958\\n    -height 1091\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 2\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 1\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -bluePencil 1\\n    -greasePencils 0\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1958\\n    -height 1091\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "60FD02EA-42A5-10C6-A84D-EEA55ADFBEBF";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 6 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 9 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 4 ".u";
select -ne :defaultRenderingList1;
select -ne :defaultTextureList1;
	setAttr -s 4 ".tx";
select -ne :initialShadingGroup;
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultRenderGlobals;
	addAttr -ci true -h true -sn "dss" -ln "defaultSurfaceShader" -dt "string";
	setAttr ".ren" -type "string" "arnold";
	setAttr ".dss" -type "string" "lambert1";
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :defaultColorMgtGlobals;
	setAttr ".cfe" yes;
	setAttr ".cfp" -type "string" "<MAYA_RESOURCES>/OCIO-configs/Maya2022-default/config.ocio";
	setAttr ".vtn" -type "string" "ACES 1.0 SDR-video (sRGB)";
	setAttr ".vn" -type "string" "ACES 1.0 SDR-video";
	setAttr ".dn" -type "string" "sRGB";
	setAttr ".wsn" -type "string" "ACEScg";
	setAttr ".otn" -type "string" "ACES 1.0 SDR-video (sRGB)";
	setAttr ".potn" -type "string" "ACES 1.0 SDR-video (sRGB)";
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :modelPanel4ViewSelectedSet;
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
connectAttr "groupId1.id" "Model_0Shape.iog.og[1].gid";
connectAttr ":modelPanel4ViewSelectedSet.mwc" "Model_0Shape.iog.og[1].gco";
connectAttr "polyTweakUV4.out" "Model_0Shape.i";
connectAttr "polyTweakUV4.uvtk[0]" "Model_0Shape.uvst[0].uvtw";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Model_0SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "pasted__Model_0SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "pasted__Model_0SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Model_0SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "pasted__Model_0SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "pasted__Model_0SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr ":defaultArnoldDisplayDriver.msg" ":defaultArnoldRenderOptions.drivers"
		 -na;
connectAttr ":defaultArnoldFilter.msg" ":defaultArnoldRenderOptions.filt";
connectAttr ":defaultArnoldDriver.msg" ":defaultArnoldRenderOptions.drvr";
connectAttr "Texture_png.oc" "None__Texture_png.c";
connectAttr "None__Texture_png.oc" "Model_0SG.ss";
connectAttr "Model_0SG.msg" "materialInfo1.sg";
connectAttr "None__Texture_png.msg" "materialInfo1.m";
connectAttr "Texture_png.msg" "materialInfo1.t" -na;
connectAttr "place2dTexture1.o" "Texture_png.uv";
connectAttr "place2dTexture1.ofu" "Texture_png.ofu";
connectAttr "place2dTexture1.ofv" "Texture_png.ofv";
connectAttr "place2dTexture1.rf" "Texture_png.rf";
connectAttr "place2dTexture1.reu" "Texture_png.reu";
connectAttr "place2dTexture1.rev" "Texture_png.rev";
connectAttr "place2dTexture1.vt1" "Texture_png.vt1";
connectAttr "place2dTexture1.vt2" "Texture_png.vt2";
connectAttr "place2dTexture1.vt3" "Texture_png.vt3";
connectAttr "place2dTexture1.vc1" "Texture_png.vc1";
connectAttr "place2dTexture1.ofs" "Texture_png.fs";
connectAttr ":defaultColorMgtGlobals.cme" "Texture_png.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "Texture_png.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "Texture_png.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "Texture_png.ws";
connectAttr "pasted__Model_0SG.msg" "pasted__materialInfo1.sg";
connectAttr "pasted__None__Texture_png.msg" "pasted__materialInfo1.m";
connectAttr "pasted__Texture_png.msg" "pasted__materialInfo1.t" -na;
connectAttr "pasted__None__Texture_png.oc" "pasted__Model_0SG.ss";
connectAttr "pasted__Texture_png.oc" "pasted__None__Texture_png.c";
connectAttr "pasted__place2dTexture1.o" "pasted__Texture_png.uv";
connectAttr "pasted__place2dTexture1.ofu" "pasted__Texture_png.ofu";
connectAttr "pasted__place2dTexture1.ofv" "pasted__Texture_png.ofv";
connectAttr "pasted__place2dTexture1.rf" "pasted__Texture_png.rf";
connectAttr "pasted__place2dTexture1.reu" "pasted__Texture_png.reu";
connectAttr "pasted__place2dTexture1.rev" "pasted__Texture_png.rev";
connectAttr "pasted__place2dTexture1.vt1" "pasted__Texture_png.vt1";
connectAttr "pasted__place2dTexture1.vt2" "pasted__Texture_png.vt2";
connectAttr "pasted__place2dTexture1.vt3" "pasted__Texture_png.vt3";
connectAttr "pasted__place2dTexture1.vc1" "pasted__Texture_png.vc1";
connectAttr "pasted__place2dTexture1.ofs" "pasted__Texture_png.fs";
connectAttr ":defaultColorMgtGlobals.cme" "pasted__Texture_png.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "pasted__Texture_png.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "pasted__Texture_png.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "pasted__Texture_png.ws";
connectAttr "pasted__Model_0SG1.msg" "pasted__materialInfo2.sg";
connectAttr "pasted__None__Texture_png1.msg" "pasted__materialInfo2.m";
connectAttr "pasted__Texture_png1.msg" "pasted__materialInfo2.t" -na;
connectAttr "pasted__None__Texture_png1.oc" "pasted__Model_0SG1.ss";
connectAttr "pasted__Model_0Shape.iog" "pasted__Model_0SG1.dsm" -na;
connectAttr "pasted__Texture_png1.oc" "pasted__None__Texture_png1.c";
connectAttr "pasted__place2dTexture2.o" "pasted__Texture_png1.uv";
connectAttr "pasted__place2dTexture2.ofu" "pasted__Texture_png1.ofu";
connectAttr "pasted__place2dTexture2.ofv" "pasted__Texture_png1.ofv";
connectAttr "pasted__place2dTexture2.rf" "pasted__Texture_png1.rf";
connectAttr "pasted__place2dTexture2.reu" "pasted__Texture_png1.reu";
connectAttr "pasted__place2dTexture2.rev" "pasted__Texture_png1.rev";
connectAttr "pasted__place2dTexture2.vt1" "pasted__Texture_png1.vt1";
connectAttr "pasted__place2dTexture2.vt2" "pasted__Texture_png1.vt2";
connectAttr "pasted__place2dTexture2.vt3" "pasted__Texture_png1.vt3";
connectAttr "pasted__place2dTexture2.vc1" "pasted__Texture_png1.vc1";
connectAttr "pasted__place2dTexture2.ofs" "pasted__Texture_png1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "pasted__Texture_png1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "pasted__Texture_png1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "pasted__Texture_png1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "pasted__Texture_png1.ws";
connectAttr "polySurfaceShape1.o" "polySplit1.ip";
connectAttr "polySplit1.out" "polySplit2.ip";
connectAttr "polySplit2.out" "polySplit3.ip";
connectAttr "polySplit3.out" "polySplit4.ip";
connectAttr "polySplit4.out" "polySplit5.ip";
connectAttr "polySplit5.out" "polySplit6.ip";
connectAttr "polyTweak1.out" "polyExtrudeFace1.ip";
connectAttr "Model_0Shape.wm" "polyExtrudeFace1.mp";
connectAttr "groupParts1.og" "polyTweak1.ip";
connectAttr "polyExtrudeFace1.out" "polyTweak2.ip";
connectAttr "polyTweak2.out" "deleteComponent1.ig";
connectAttr "deleteComponent1.og" "deleteComponent2.ig";
connectAttr "deleteComponent2.og" "deleteComponent3.ig";
connectAttr "deleteComponent3.og" "deleteComponent4.ig";
connectAttr "deleteComponent4.og" "deleteComponent5.ig";
connectAttr "deleteComponent5.og" "deleteComponent6.ig";
connectAttr "deleteComponent6.og" "deleteComponent7.ig";
connectAttr "deleteComponent7.og" "deleteComponent8.ig";
connectAttr "deleteComponent8.og" "deleteComponent9.ig";
connectAttr "deleteComponent9.og" "deleteComponent10.ig";
connectAttr "deleteComponent10.og" "deleteComponent11.ig";
connectAttr "deleteComponent11.og" "deleteComponent12.ig";
connectAttr "polySplit6.out" "groupParts1.ig";
connectAttr "groupId1.id" "groupParts1.gi";
connectAttr "file1.oc" "aiStandardSurface1.base_color";
connectAttr "aiStandardSurface1.out" "aiStandardSurface1SG.ss";
connectAttr "Model_0Shape.iog" "aiStandardSurface1SG.dsm" -na;
connectAttr "aiStandardSurface1SG.msg" "materialInfo2.sg";
connectAttr "aiStandardSurface1.msg" "materialInfo2.m";
connectAttr "file1.msg" "materialInfo2.t" -na;
connectAttr ":defaultColorMgtGlobals.cme" "file1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "file1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "file1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "file1.ws";
connectAttr "place2dTexture2.c" "file1.c";
connectAttr "place2dTexture2.tf" "file1.tf";
connectAttr "place2dTexture2.rf" "file1.rf";
connectAttr "place2dTexture2.mu" "file1.mu";
connectAttr "place2dTexture2.mv" "file1.mv";
connectAttr "place2dTexture2.s" "file1.s";
connectAttr "place2dTexture2.wu" "file1.wu";
connectAttr "place2dTexture2.wv" "file1.wv";
connectAttr "place2dTexture2.re" "file1.re";
connectAttr "place2dTexture2.of" "file1.of";
connectAttr "place2dTexture2.r" "file1.ro";
connectAttr "place2dTexture2.n" "file1.n";
connectAttr "place2dTexture2.vt1" "file1.vt1";
connectAttr "place2dTexture2.vt2" "file1.vt2";
connectAttr "place2dTexture2.vt3" "file1.vt3";
connectAttr "place2dTexture2.vc1" "file1.vc1";
connectAttr "place2dTexture2.o" "file1.uv";
connectAttr "place2dTexture2.ofs" "file1.fs";
connectAttr "deleteComponent12.og" "polyAutoProj1.ip";
connectAttr "Model_0Shape.wm" "polyAutoProj1.mp";
connectAttr "polyAutoProj1.out" "polyTweakUV1.ip";
connectAttr "polyTweakUV1.out" "polyAutoProj2.ip";
connectAttr "Model_0Shape.wm" "polyAutoProj2.mp";
connectAttr "polyAutoProj2.out" "polyTweakUV2.ip";
connectAttr "polyTweakUV2.out" "deleteComponent13.ig";
connectAttr "deleteComponent13.og" "deleteComponent14.ig";
connectAttr "deleteComponent14.og" "deleteComponent15.ig";
connectAttr "deleteComponent15.og" "deleteComponent16.ig";
connectAttr "deleteComponent16.og" "deleteComponent17.ig";
connectAttr "deleteComponent17.og" "deleteComponent18.ig";
connectAttr "deleteComponent18.og" "deleteComponent19.ig";
connectAttr "deleteComponent19.og" "polyDelEdge1.ip";
connectAttr "polyDelEdge1.out" "polyAutoProj3.ip";
connectAttr "Model_0Shape.wm" "polyAutoProj3.mp";
connectAttr "polyAutoProj3.out" "polyTweakUV3.ip";
connectAttr "polyTweakUV3.out" "deleteComponent20.ig";
connectAttr "deleteComponent20.og" "deleteComponent21.ig";
connectAttr "deleteComponent21.og" "polyExtrudeEdge1.ip";
connectAttr "Model_0Shape.wm" "polyExtrudeEdge1.mp";
connectAttr "polyTweak3.out" "polyExtrudeEdge2.ip";
connectAttr "Model_0Shape.wm" "polyExtrudeEdge2.mp";
connectAttr "polyExtrudeEdge1.out" "polyTweak3.ip";
connectAttr "polyTweak4.out" "polyMergeVert1.ip";
connectAttr "Model_0Shape.wm" "polyMergeVert1.mp";
connectAttr "polyExtrudeEdge2.out" "polyTweak4.ip";
connectAttr "polyMergeVert1.out" "polyAutoProj4.ip";
connectAttr "Model_0Shape.wm" "polyAutoProj4.mp";
connectAttr "polyAutoProj4.out" "polyTweakUV4.ip";
connectAttr "Model_0SG.pa" ":renderPartition.st" -na;
connectAttr "pasted__Model_0SG.pa" ":renderPartition.st" -na;
connectAttr "pasted__Model_0SG1.pa" ":renderPartition.st" -na;
connectAttr "aiStandardSurface1SG.pa" ":renderPartition.st" -na;
connectAttr "None__Texture_png.msg" ":defaultShaderList1.s" -na;
connectAttr "pasted__None__Texture_png.msg" ":defaultShaderList1.s" -na;
connectAttr "pasted__None__Texture_png1.msg" ":defaultShaderList1.s" -na;
connectAttr "aiStandardSurface1.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "pasted__place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "pasted__place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "Texture_png.msg" ":defaultTextureList1.tx" -na;
connectAttr "pasted__Texture_png.msg" ":defaultTextureList1.tx" -na;
connectAttr "pasted__Texture_png1.msg" ":defaultTextureList1.tx" -na;
connectAttr "file1.msg" ":defaultTextureList1.tx" -na;
// End of Intersex.ma
