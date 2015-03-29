var
  a:array[1..40] of longint;
  x:int64;
  n,i,j,k:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  x:=1;
  for i:=n+2 to n*2 do
    begin
      j:=i;
      for k:=2 to i do
        while j mod k=0 do
          begin
            inc(a[k]);
            j:=j div k;
          end;
    end;
  for i:=2 to n do
    begin
      j:=i;
      for k:=2 to i do
        while j mod k=0 do
          begin
            dec(a[k]);
            j:=j div k;
          end;
    end;
  for i:=1 to 40 do
    for j:=1 to a[i] do
      x:=x*int64(i);
  writeln(x);
end.