var
  a:array[1..20] of longint;
  s,p,q:string;
  n,i,j,t:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        str(a[i],p);str(a[j],q);
        if q+p>p+q then
          begin
            t:=a[i];a[i]:=a[j];a[j]:=t;
          end;
      end;
  s:='';
  for i:=1 to n do
    begin
      str(a[i],p);
      s:=s+p;
    end;
  writeln(s);
end.