# How to use a Reg_Free WINRT component in a C#/WINUI3 project

### 1. Create a WINRT component in C++/CX

### 2. Create a C# projection project (typically a library class project)
```xml
<!-- add following to .csproj-->
  <PropertyGroup>
    <CSWinRTIncludes>
        MathOperate;
    </CSWinRTIncludes>
    <CsWinRTGeneratedFilesDir>$(OutDir)</CsWinRTGeneratedFilesDir>
    <CSWinRTWindowsMetadata>local</CSWinRTWindowsMetadata>
    <CsWinRTGenerateProjection>true</CsWinRTGenerateProjection>
  </PropertyGroup>

  <ItemGroup>
    <PackageReference Include="Microsoft.Windows.CsWinRT" Version="2.0.7" />
  </ItemGroup> 

  
     <!-- CsWinRT input projects and assemblies -->
  <ItemGroup>
    <ProjectReference Include="..\MathOperate\MathOperate.vcxproj" PrivateAssets="All" />
  </ItemGroup>

```

### 3. Create c#/WinUI3 project and add following:
```xml
<!-- add to following to .csproj-->
<ItemGroup>
    <ProjectReference Include="..\MathOperate.projection\MathOperate.projection.csproj" />
  </ItemGroup>

  <ItemGroup>
  <!--both must be included-->
    <Reference Include="../bin/MathOperate/MathOperate.dll">
      <IsWinmdFile>false</IsWinmdFile>
    </Reference>
    <Reference Include="../bin/MathOperate/MathOperate.winmd">
      <IsWinmdFile>true</IsWinmdFile>
    </Reference>
  </ItemGroup>
```

```xml
<!-- add following to Package.appxmanifest-->
  <Extensions>
    <Extension Category="windows.activatableClass.inProcessServer">
      <InProcessServer>
        <Path>MathOperate.dll</Path>
        <ActivatableClass ActivatableClassId="MathOperate.Class" ThreadingModel="both" />
      </InProcessServer>
    </Extension>
  </Extensions>
```

<font color="red" size=7>[refer this to enable mix debug, breakpoints between c# and c++](https://learn.microsoft.com/zh-cn/visualstudio/debugger/how-to-debug-managed-and-native-code?view=vs-2022)</font>

**then you can use the WINRT component in the C#/WinUI3 project**

### as for details of related attributes, you can refer to Win2d source code, whichi is also a excellent project for learn wrl and c++/winrt
