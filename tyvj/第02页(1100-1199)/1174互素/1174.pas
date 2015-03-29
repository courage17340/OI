var
  a:array[1..1000000] of longint;
  i,j,n,x:longint;
begin
  j:=0;
  read(n);x:=n;
  fillchar(a,sizeof(a),0);
  for i:=2 to trunc(sqrt(n)) do
    begin
      if n mod i=0 then begin inc(j);a[j]:=i;end;
      while n mod i=0 do n:=n div i;
    end;
  if n>1 then begin inc(j);a[j]:=n;end;
  for i:=1 to j do
    x:=x-x div a[i];
  writeln(x);
end.