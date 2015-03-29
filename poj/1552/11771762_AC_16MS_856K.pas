var
  a:array[1..100] of longint;
  v:array[1..200] of boolean;
  i,j,s,x:longint;
begin
  while not eof do
    begin
      fillchar(v,sizeof(v),false);
      j:=0;
      while not eoln do
        begin
          read(x);
          if x=-1 then halt;
          if x=0 then break;
          inc(j);
          a[j]:=x;
          v[2*x]:=true;
        end;
      readln;
      s:=0;
      for i:=1 to j do if v[a[i]] then inc(s);
      writeln(s);
    end;
end.