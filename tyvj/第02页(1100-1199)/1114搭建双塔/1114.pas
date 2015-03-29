var
  f:array[0..1000,0..1000] of boolean;
  a,s:array[0..100] of longint;
  i,n,max,j,k:longint;
function min(a,b:longint):longint;
begin
  min:=a;if a>b then min:=b;
end;
begin
  read(n);max:=0;
  s[0]:=0;
  for i:=1 to n do begin read(a[i]);s[i]:=s[i-1]+a[i];inc(max,a[i]);end;
  max:=max div 2;
  fillchar(f,sizeof(f),false);
  f[0,0]:=true;
  for k:=1 to n do
    for i:=min(s[k],max) downto 0 do
      for j:=min(s[k],max) downto 0 do
        begin
          if i>=a[k] then f[i,j]:=f[i,j] or f[i-a[k],j];
          if j>=a[k] then f[i,j]:=f[i,j] or f[i,j-a[k]];
        end;
  i:=max;
  while not f[i,i] do dec(i);
  if i=0 then writeln('Impossible') else writeln(i);
end.
