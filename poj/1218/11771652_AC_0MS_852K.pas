var
  a:array[1..100] of boolean;
  n,i,j,k,p,s:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(p);
      fillchar(a,sizeof(a),true);
      for j:=2 to p do
        for k:=1 to p div j do
          a[j*k]:=not a[j*k];
      s:=0;
      for j:=1 to p do
        if a[j] then inc(s);
      writeln(s);
    end;
end.