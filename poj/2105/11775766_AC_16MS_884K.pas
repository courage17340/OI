var
  s:string;
  n,i,j,k,x:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to 4 do
        begin
          x:=0;
          for k:=1 to 8 do x:=x*2+ord(s[k])-48;
          delete(s,1,8);
          write(x);
          if j=4 then writeln else write('.');
        end;
    end;
end.