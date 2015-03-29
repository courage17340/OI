var
  a:array[1..1000] of longint;
  f:array[0..1000,-5000..5000] of longint;
  n,i,j,x,y,s:longint;
function min(a,b:longint):longint;
begin
  min:=a;if a>b then min:=b;
end;
begin
  read(n);
  for i:=1 to n do begin read(x,y);a[i]:=y-x;end;
  s:=0;for i:=1 to n do s:=s+a[i];
  fillchar(f,sizeof(f),1);
  f[0,s]:=0;
  for i:=1 to n do
    for j:=-5000 to 5000 do
      begin
         f[i,j]:=f[i-1,j];
         if (j+2*a[i]<=5000)and(j+2*a[i]>=-5000) then f[i,j]:=min(f[i,j],f[i-1,j+2*a[i]]+1);
      end;
  for j:=0 to 5000 do
    if (f[n,j]<6000)or(f[n,-j]<6000) then begin writeln(min(f[n,j],f[n,-j]));break;end;
end.