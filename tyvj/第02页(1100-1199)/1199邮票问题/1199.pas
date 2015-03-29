var
  a:array[0..100] of longint;
  f:array[0..26501] of longint;
  m,n,i,j:longint;
function min(a,b:longint):longint;
begin
  min:=a;if b<a then min:=b;
end;
procedure print;
begin
  writeln(i-1);halt;
end;
begin
  read(n);read(m);
  fillchar(f,sizeof(f),0);
  for i:=1 to m do read(a[i]);
  for i:=1 to 26501 do
    begin
      f[i]:=444444;
      for j:=m downto 1 do
        if i>=a[j] then f[i]:=min(f[i],f[i-a[j]]);
      inc(f[i]);
      if f[i]>n then print;
    end;
end.