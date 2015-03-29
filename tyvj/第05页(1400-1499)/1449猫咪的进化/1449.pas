var
  f:array[0..800000,0..2] of real;
  a:array[0..800000] of real;
  i,n:longint;
function max(a,b:real):real;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  fillchar(f,sizeof(f),0);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin
      f[i,0]:=max(f[i-1,0],f[i-1,1]);f[i,0]:=max(f[i,0],f[i-1,2]);
      f[i,1]:=max(f[i-1,0],f[i-1,1])+a[i];
      f[i,2]:=max(f[i-1,0],f[i-1,1])+sqr(a[i]); 
    end;
  f[n,0]:=max(f[n,0],f[n,1]);
  f[n,0]:=max(f[n,0],f[n,2]);
  writeln(f[n,0]:0:4);
end.