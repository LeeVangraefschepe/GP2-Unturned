//=============================================================================
//// Shader uses position and texture
//=============================================================================
SamplerState samPoint
{
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Mirror;
    AddressV = Mirror;
};

Texture2D gTexture;
float gEffectIntensity = 1.0f;

/// Create Depth Stencil State (ENABLE DEPTH WRITING)
/// Create Rasterizer State (Backface culling) 


//IN/OUT STRUCTS
//--------------
struct VS_INPUT
{
    float3 Position : POSITION;
	float2 TexCoord : TEXCOORD0;

};

struct PS_INPUT
{
    float4 Position : SV_POSITION;
	float2 TexCoord : TEXCOORD1;
};


//VERTEX SHADER
//-------------
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;

	// Set the Position
    output.Position = float4(input.Position, 1);

	// Set the TexCoord
    output.TexCoord = input.TexCoord;
	
	return output;
}


// PIXEL SHADER
// ------------
float4 PS(PS_INPUT input) : SV_Target
{
    // Step 1: Sample the texture
    float4 color = gTexture.Sample(samPoint, input.TexCoord);
    
    // Step 2: Determine the distance from the screen edges
    float2 screenCenter = float2(0.5, 0.5); // Assuming normalized screen coordinates
    float2 screenOffset = abs(input.TexCoord - screenCenter);
    float edgeDistance = max(screenOffset.x, screenOffset.y);
    
    // Step 3: Adjust the color based on the edge distance and effect intensity
    float edgeIntensity = saturate(edgeDistance * 2.0f - 0.5f);
    float4 bloodColor = float4(1.0f, 0.0f, 0.0f, 1.0f); // Red color for blood effect
    float4 finalColor = lerp(color, bloodColor, edgeIntensity * gEffectIntensity);
    
    // Step 4: Return the final color
    return finalColor;
}


//TECHNIQUE
//---------
technique11 Grayscale
{
    pass P0
    {          
        // Set states...
		SetVertexShader( CompileShader( vs_4_0, VS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PS() ) );
    }
}

