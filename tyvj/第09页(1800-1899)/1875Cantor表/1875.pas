var
  i,j,L,m,k,n:longint;
procedure init;
begin
  readln(n);
end;
procedure work;
begin
  k:=0;
  for L:=2 to 100001 do
    begin
      if odd(L)
        then
          for i:=L-1 downto 1 do
            begin
              k:=k+1;
              if k=n then exit;
            end
        else
          for i:=1 to L-1 do
            begin
              k:=k+1;
              if k=n then exit;
            end;
    end;
  for L:=100002 to 200000 do
    begin
      if odd(L)
        then
          for i:=n downto L-n do
            begin
              k:=k+1;
              if k=n then exit;
            end
        else
          for i:=L-n to n do
            begin
              k:=k+1;
              if k=n then exit;
            end;
    end;
end;
procedure print;
begin
  write(L-i,'/',i);
end;
begin
  init;
  work;
  print;
end.